#include <gb/gb.h>
#include <gb/metasprites.h>
#include <gb/cgb.h>

#include "player_update.h"
#include "player_init.h"
#include "player_movement.h"
#include "player_shoot.h"
#include "player_jump.h"
#include "bullet_obj.h"

#include "fliped_rootpack_testy.h"
#include "potato_window.h"

#define PLAYER_BULLET_COUNT 4

///////////////////////////////////////////////////////////////////////////////
//FOWARD DECLA

void get_input();
void init_audio();
void test_audio();


unsigned char windowtestmap_tilemap[] = {
  0x00, 0x00, 0x1e, 0x13, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x25, 0x26, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x13, 0x2c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
  0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
  0x13, 0x13, 0x13, 0x13, 0x13, 0x13
};

unsigned int windowtestmap_len = 78;

Player player;

void main(){
    init_audio();

    set_bkg_data(0,fliped_rootpack_testy_TILE_COUNT, fliped_rootpack_testy_tiles);
    set_bkg_tiles(0,0,32,32,fliped_rootpack_testy_map);
    SHOW_BKG;

    uint8_t x = 6;
    uint8_t y = 8;
    //potato window
    set_win_submap(0,0,14,8,(fliped_rootpack_testy_map + x + (y * 32)),32);
    move_win(55,64);    
    

    SHOW_WIN;

    

    // remaps the palette
    // Bit 7-6 - Color for index 3
    // Bit 5-4 - Color for index 2
    // Bit 3-2 - Color for index 1
    // Bit 1-0 - Color for index 0
    // 0	White
    // 1	Light gray
    // 2	Dark gray
    // 3	Black
    //           3 1 0 transparent
    OBP0_REG = 0b11010000;
    player_init(&player);
    //load bullet tile into vram
    set_sprite_data(50, 1, sprite_player_bullet_tile);
    init_bullets(&player.bulletPool, PLAYER_BULLET_COUNT, 50, 4);
    
    SHOW_SPRITES;
    //Quick test for audio.
    wait_vbl_done();
    test_audio();

    uint8_t i;
    Bullet* playerBullets = player.bulletPool.bullets;
    while(1){
        
        get_input();
        
        player_update(&player);


        for(i = 0; i < PLAYER_BULLET_COUNT; i++){
            bullet_update(playerBullets);
            playerBullets++;
        }
        playerBullets = player.bulletPool.bullets;

        
        
        wait_vbl_done();
    }

    
}

/**
 * Main input loop for gameplay
 */
void get_input(){
    
    uint8_t joy = joypad();

    if(joy & J_RIGHT){
        player_move_right(&player);
    }
    else if(joy & J_LEFT){
        player_move_left(&player);
    }
    if(joy & J_A){
        player.jumping = 1;
        //test_audio();
    }
    if(joy & J_B){
        shoot(&player);
    }
}

//Turns on audio and sets it to full volume.
void init_audio(){
    //registers are in a specific order!
    NR52_REG = 0x80;// is 1000 0000 in binary and turns on sound
    NR50_REG = 0x77;// sets the volume for both left and right channel just set to max 0x77
    NR51_REG = 0xFF;// is 1111 1111 in binary, select which channels we wantt to use in this case all of them.
                    // One bit for the L one bit fo the R of all four

}

void test_audio(){
    // see https://github.com/bwhitman/pushpin/blob/master/src/gbsound.txt
    // chanel 1 register 0, Frequency sweep settings
    // 7	Unused
    // 6-4	Sweep time(update rate) (if 0, sweeping is off)
    // 3	Sweep Direction (1: decrease, 0: increase)
    // 2-0	Sweep RtShift amount (if 0, sweeping is off)
    // 0001 0110 is 0x16, sweet time 1, sweep direction increase, shift ammount per step 110 (6 decimal)
    NR10_REG = 0x16;

    // chanel 1 register 1: Wave pattern duty and sound length
    // Channels 1 2 and 4
    // 7-6	Wave pattern duty cycle 0-3 (12.5%, 25%, 50%, 75%), duty cycle is how long a quadrangular  wave is "on" vs "of" so 50% (2) is both equal.
    // 5-0 sound length (higher the number shorter the sound)
    // 01000000 is 0x40, duty cycle 1 (25%), wave length 0 (long)
    NR11_REG = 0x40;

    // chanel 1 register 2: Volume Envelope (Makes the volume get louder or quieter each "tick")
    // On Channels 1 2 and 4
    // 7-4	(Initial) Channel Volume
    // 3	Volume sweep direction (0: down; 1: up)
    // 2-0	Length of each step in sweep (if 0, sweeping is off)
    // NOTE: each step is n/64 seconds long, where n is 1-7	
    // 0111 0011 is 0x73, volume 7, sweep down, step length 3
    NR12_REG = 0x73;

    // chanel 1 register 3: Frequency LSbs (Least Significant bits) and noise options
    // for Channels 1 2 and 3
    // 7-0	8 Least Significant bits of frequency (3 Most Significant Bits are set in register 4)
    NR13_REG = 0x00;

    // chanel 1 register 4: Playback and frequency MSbs
    // Channels 1 2 3 and 4
    // 7	Initialize (trigger channel start, AKA channel INIT) (Write only)
    // 6	Consecutive select/length counter enable (Read/Write). When "0", regardless of the length of data on the NR11 register, sound can be produced consecutively.  When "1", sound is generated during the time period set by the length data contained in register NR11.  After the sound is ouput, the Sound 1 ON flag, at bit 0 of register NR52 is reset.
    // 5-3	Unused
    // 2-0	3 Most Significant bits of frequency
    // 1100 0011 is 0xC3, initialize, no consecutive, frequency = MSB + LSB = 011 0000 0000 = 0x300
    NR14_REG = 0xC3;	 
}

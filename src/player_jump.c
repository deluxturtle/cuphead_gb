#include "player_jump.h"

const uint8_t FALLSPEED = 3;
const uint8_t JUMPFRAMES = 22;
const uint8_t FALLFRAMES = 18;
//height of player each frame from ground
const uint8_t JUMPPATTERN[23] = {0,3,6,9,12,15,18,21,24,26,28,29,30,31,32,33,34,35,36,37,38,39,39};
const uint8_t FALLPATTERN[19] = {0,3,6,9,12,15,18,21,24,26,28,30,32,34,36,37,38,39,39};

uint8_t jump_index;
uint8_t fall_index;
uint8_t grounded = 1;
uint8_t jump_ystart;

void player_jump(){
    
    if(grounded == 1){
        player.jumping = 1;
        grounded = 0;
        jump_ystart = player.pos.y;
        jump_index = 0;
        fall_index = FALLFRAMES;
        animState = JUMP;
    }
    else{
        if(jump_index < JUMPFRAMES){//going up
            jump_index++;
            player.pos.y = jump_ystart - JUMPPATTERN[jump_index];
        }
        else if(fall_index > 0){
            fall_index--;
            player.pos.y = jump_ystart - FALLPATTERN[fall_index];
        }
        else{//no platform, use a gravity to keep moving.
            player.pos.y+=FALLSPEED;
            //if hit bottom trigger landing
            if(player.pos.y >= MAXWNDPOSY){
                player.jumping = 0;
                jump_index = 0;
                grounded = 1;
                player.pos.y = MAXWNDPOSY;
                animState = IDLE;
            }
        }
    }
}
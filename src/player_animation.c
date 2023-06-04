#include "player_animation.h"


metasprite_t *const *animations[4];
AnimState animState;
AnimState prevAnimState;


uint8_t animation_tile;
uint8_t sprite_tile_index = 0;

uint8_t counter = 0;
uint8_t *anim_frames;

uint8_t cur_frame = 1;//animation frame counter;
int8_t anim_dir = 1; //direciton to go through animation.


//IDLE ANIMATION
const uint8_t CUPH_IDLE_TILE_START = 0;
const uint8_t idle_frames = 8;
const uint8_t idle_frame_index[8] = {0, 0, 0, 1, 2, 3, 3, 3};
//FIRE ANIMATION
const uint8_t CUPH_FIRE_TILE_START = 12;
const uint8_t fire_frames = 5;
const uint8_t fire_frames_index[5] = {0,0,1,1,0}; //flipped the frames to do the up motion first.
//JUMP ANIMATION
const uint8_t CUPH_JUMP_TILE_START = 18;
const uint8_t jump_frames = 16;
const uint8_t jump_frames_index[16] = {0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7};




void player_init_anim()
{
    set_sprite_data(0, sizeof(sprite_player_idle_tiles)>>4, sprite_player_idle_tiles);

    set_sprite_data(CUPH_FIRE_TILE_START, sizeof(sprite_player_fire_tiles)>>4, sprite_player_fire_tiles);

    set_sprite_data(CUPH_JUMP_TILE_START, sizeof(sprite_player_jump_tiles)>>4, sprite_player_jump_tiles);

    animations[JUMP] = sprite_player_jump_metasprites;
    animations[FIRE] = sprite_player_fire_metasprites;
    animations[IDLE] = sprite_player_idle_metasprites;
    animState = IDLE;
    prevAnimState = animState;
    

    player_reset_anim();
}

void player_reset_anim()
{
    switch (animState)
    {
        case JUMP:
            anim_frames = jump_frames_index;
            animation_tile = CUPH_JUMP_TILE_START;
            break;
        case FIRE:
            anim_frames = fire_frames_index;
            animation_tile = CUPH_FIRE_TILE_START;
            break;
        default:
            anim_frames = idle_frame_index;
            animation_tile = CUPH_IDLE_TILE_START;
            break;
    }
    
    anim_dir = 1;
    //little transition
    if(prevAnimState == FIRE && animState == IDLE){
        anim_dir = -1;
        cur_frame = idle_frames;
    }
    else{
        cur_frame = 1;
    }
    
}

void play_idle()
{
    cur_frame += anim_dir;
    if (cur_frame > idle_frames)
    {
        cur_frame = idle_frames;
        anim_dir = -1;
    }
    else if (cur_frame == 1)
    {
        anim_dir = 1;
    }
}

void play_jump()
{
    cur_frame += anim_dir;
    if (cur_frame > jump_frames)
    {
        cur_frame = 1;
    }
}

void play_fire()
{
    cur_frame += anim_dir;
    if (cur_frame > fire_frames)
    {
        cur_frame = 1;
        animState = IDLE;
    }
}


void player_update_animation()
{
    //if animation state changed go back to frame 1;
    if(prevAnimState != animState){
        player_reset_anim();
        prevAnimState = animState;
    }
    //animation frame rate
    counter ++;
    if(counter > 1){
        counter = 0;
        switch (animState)
        {
            case JUMP:
                play_jump();
                break;
            case FIRE:
                play_fire();
                break;

            default:
                play_idle();
                break;
        }
        
    }
}
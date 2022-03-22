#include "player_sprites.h"

metasprite_t *const *animations[4];

AnimState animState = IDLE;
AnimState prevAnimState;
uint8_t animation_tile;
uint8_t sprite_tile_index = 0;
uint8_t CUPH_IDLE_TILE_START;
uint8_t CUPH_FIRE_TILE_START;

//animation frame counter;
int8_t cur_frame = 1;
int8_t anim_dir = 1; //direciton to go through animation.

//IDLE ANIMATION
const uint8_t idle_frames = 8;
const uint8_t idle_frame_index[8] = {0, 0, 0, 1, 2, 3, 3, 3};
//FIRE ANIMATION
const uint8_t fire_frames = 4;
const uint8_t fire_frames_index[4] = {0,0,1,1}; //flipped the frames to do the up motion first.

void player_init_anim()
{
    set_sprite_data(0, sizeof(sprite_player_idle_data)>>4, sprite_player_idle_data);
    CUPH_IDLE_TILE_START = sprite_tile_index;
    sprite_tile_index += sizeof(sprite_player_idle_data)>>4;
    set_sprite_data(sprite_tile_index, sizeof(sprite_player_fire_data)>>2, sprite_player_fire_data);
    CUPH_FIRE_TILE_START = sprite_tile_index;

    animState = FIRE;
    animations[animState] = sprite_player_fire_metasprites;
    animState = IDLE;
    animations[animState] = sprite_player_idle_metasprites;
    prevAnimState = animState;
    player_reset_anim();
}

void player_reset_anim()
{
    switch (animState)
    {
    case FIRE:
        animation_tile = CUPH_FIRE_TILE_START;
        break;
    default:
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

void play_fire()
{
    cur_frame += anim_dir;
    if (cur_frame > fire_frames)
    {
        cur_frame = 1;
        animState = IDLE;
    }
}


void player_update_sprite()
{
    //if animation state changed go back to frame 1;
    if(prevAnimState != animState){
        player_reset_anim();
        prevAnimState = animState;
    }

    //animation frame rate
    if (sys_time % 3 == 0)
    {
        switch (animState)
        {
            case FIRE:
                play_fire();
                break;

            default:
                play_idle();
                break;
        }
    }
    if (animations[animState] != NULL)
        move_metasprite(animations[animState][idle_frame_index[cur_frame - 1]], animation_tile, 0, player.pos.x, player.pos.y);
    
}
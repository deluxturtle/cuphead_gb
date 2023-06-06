#include "player_animation.h"


uint8_t sprite_tile_index = 0;

uint8_t counter = 0;
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




void player_init_anim(Player* player)
{
    set_sprite_data(0, sizeof(sprite_player_idle_tiles)>>4, sprite_player_idle_tiles);

    set_sprite_data(CUPH_FIRE_TILE_START, sizeof(sprite_player_fire_tiles)>>4, sprite_player_fire_tiles);

    set_sprite_data(CUPH_JUMP_TILE_START, sizeof(sprite_player_jump_tiles)>>4, sprite_player_jump_tiles);

    player->animationState.animations[JUMP] = sprite_player_jump_metasprites;
    player->animationState.animations[FIRE] = sprite_player_fire_metasprites;
    player->animationState.animations[IDLE] = sprite_player_idle_metasprites;
    player->animationState.animation = IDLE;
    player->animationState.prevAnimation = player->animationState.animation;
    

    player_reset_anim(player);
}

void player_reset_anim(Player* player)
{
    switch (player->animationState.animation)
    {
        case JUMP:
            player->animationState.anim_frames = jump_frames_index;
            player->animationState.animation_tile = CUPH_JUMP_TILE_START;
            break;
        case FIRE:
            player->animationState.anim_frames = fire_frames_index;
            player->animationState.animation_tile = CUPH_FIRE_TILE_START;
            break;
        default:
            player->animationState.anim_frames = idle_frame_index;
            player->animationState.animation_tile = CUPH_IDLE_TILE_START;
            break;
    }
    
    anim_dir = 1;
    //little transition
    if(player->animationState.prevAnimation == FIRE && player->animationState.animation == IDLE){
        anim_dir = -1;
        player->animationState.cur_frame = idle_frames;
    }
    else{
        player->animationState.cur_frame = 1;
    }
    
}

void play_idle(Player* player)
{
    player->animationState.cur_frame += anim_dir;
    if (player->animationState.cur_frame > idle_frames)
    {
        player->animationState.cur_frame = idle_frames;
        anim_dir = -1;
    }
    else if (player->animationState.cur_frame == 1)
    {
        anim_dir = 1;
    }
}

void play_jump(Player* player)
{
    player->animationState.cur_frame += anim_dir;
    if (player->animationState.cur_frame > jump_frames)
    {
        player->animationState.cur_frame = 1;
    }
}

void play_fire(Player* player)
{
    player->animationState.cur_frame += anim_dir;
    if (player->animationState.cur_frame > fire_frames)
    {
        player->animationState.cur_frame = 1;
        player->animationState.animation = IDLE;
    }
}


void player_update_animation(Player* player)
{
    //if animation state changed go back to frame 1;
    if(player->animationState.prevAnimation != player->animationState.animation){
        player_reset_anim(player);
        player->animationState.prevAnimation = player->animationState.animation;
    }
    //animation frame rate
    counter ++;
    if(counter > 1){
        counter = 0;
        switch (player->animationState.animation)
        {
            case JUMP:
                play_jump(player);
                break;
            case FIRE:
                play_fire(player);
                break;

            default:
                play_idle(player);
                break;
        }
        
    }
}
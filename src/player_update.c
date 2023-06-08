#include "player_update.h"


void player_update(Player* player){
    player_update_animation(player);

    //I wanted to do a function but its probably ruining my stack overhead.
    if(player->fireDelay > 0)
        player->fireDelay--;
    
    switch(player->facingDirection){
        case RIGHT:
            move_metasprite(player->animationState.animations[player->animationState.animation][player->animationState.anim_frames[player->animationState.cur_frame - 1]], player->animationState.animation_tile, 0, player->pos.x, player->pos.y);
            break;
        case LEFT:
            move_metasprite_vflip(player->animationState.animations[player->animationState.animation][player->animationState.anim_frames[player->animationState.cur_frame - 1]], player->animationState.animation_tile, 0, player->pos.x, player->pos.y);
            break;
    }
    
}

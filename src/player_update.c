#include "player_update.h"


void player_update(Player* player){
    player_update_animation(player);

    move_metasprite(player->animationState.animations[player->animationState.animation][player->animationState.anim_frames[player->animationState.cur_frame - 1]], player->animationState.animation_tile, 0, player->pos.x, player->pos.y);
}

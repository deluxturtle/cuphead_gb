#include "player_base.h"

const uint8_t startx = 55;
const uint8_t starty = 55;




void player_init(Player* player){
    player->pos.x = 55;
    player->pos.y = 55;
    player->jumping = 0;
    player->collider.pos = &player->pos;
    
    player_init_anim();
}

void player_update(Player* player){
    player_update_animation(player);

    move_metasprite(player->animationState.animations[player->animationState.animation][player->animationState.anim_frames[player->animationState.cur_frame - 1]], player->animationState.animation_tile, 0, player->pos.x, player->pos.y);
}

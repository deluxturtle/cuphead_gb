#include "player_base.h"

const uint8_t startx = 55;
const uint8_t starty = 55;
Player player;



void player_init(){
    player.pos.x = 55;
    player.pos.y = 55;
    player.jumping = 0;
    player.collider.pos = &player.pos;

    player_init_anim();
}

void player_update(){
    player_update_animation();
    move_metasprite(animations[animState][anim_frames[cur_frame - 1]], animation_tile, 0, player.pos.x, player.pos.y);
}

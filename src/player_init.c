#include "player_init.h"

const uint8_t startx = 55;
const uint8_t starty = 55;

void player_init(Player* player){
    player->pos.x = 55;
    player->pos.y = 55;
    player->jumping = 0;
    player->collider.pos = &player->pos;
    player->fireDelay = 0;
    player->facingDirection = RIGHT;
    
    player_init_anim(player);
}
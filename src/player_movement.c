#include "player_movement.h"

const uint8_t movespeed = 1;

void player_move_right(Player* player){
    player->pos.x += movespeed;
    player->facingDirection = RIGHT;
}

void player_move_left(Player* player){
    player->facingDirection = LEFT;
    player->pos.x -= movespeed;
}
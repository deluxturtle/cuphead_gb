#include "player_movement.h"

const uint8_t movespeed = 1;

void player_move_right(Player* player){
    player->pos.x += movespeed;
}

void player_move_left(Player* player){
    player->pos.x -= movespeed;
}
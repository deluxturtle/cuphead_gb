#ifndef PLAYER_BASE_H
#define PLAYER_BASE_H

#include <gb/gb.h>
#include "position.h"
#include "collider_c.h"
#include "player_jump.h"
#include "player_movement.h"
#include "player_animation.h"

typedef struct Player{
    Position pos;
    CircleCol collider;
    uint8_t jumping;
    uint8_t frame;
}Player;

extern Player player;
extern const uint8_t startx;
extern const uint8_t starty;

void player_init();
void player_update();
void player_shoot();
void player_jump();

#endif
#ifndef PLAYER_BASE_H
#define PLAYER_BASE_H

#include <gb/gb.h>
#include "position.h"
#include "collider_c.h"
#include "bullet_pool.h"
#include "player_animation.h"

typedef struct Player{
    Position pos;
    CircleCol collider;
    BulletPool* bulletPool;
    uint8_t jumping;
    uint8_t frame;
    AnimationState animationState;
}Player;

extern const uint8_t startx;
extern const uint8_t starty;

void player_init(Player* player);
void player_update(Player* player);

#endif
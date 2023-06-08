#ifndef PLAYER_BASE_H
#define PLAYER_BASE_H

#include <gb/gb.h>
#include "position.h"
#include "collider_c.h"
#include "bullet_pool.h"
#include "player_animation_state.h"

typedef struct Player{
    Position pos;
    CircleCol collider;
    BulletPool bulletPool;
    uint8_t jumping;
    uint8_t frame;
    AnimationState animationState;
    uint8_t fireDelay;
    Facing facingDirection;
}Player;


#endif
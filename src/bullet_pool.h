#ifndef BULLET_POOL_H
#define BULLET_POOL_H
#include <gb/gb.h>
#include "bullet_obj.h"
#include "stack.h"
#include "../res/sprite_player_bullet.h"

#define MAX_BULLETS 4


typedef struct BulletPool{
    Bullet bullets[4];
    stack* freeBullets;
}BulletPool;

void init_bullets(BulletPool* pool, uint8_t number_of_bullets, uint8_t tile, uint8_t startingSprite);

#endif
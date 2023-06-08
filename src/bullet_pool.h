#ifndef BULLET_POOL_H
#define BULLET_POOL_H
#include <gb/gb.h>
#include "bullet_struct.h"
#include "../res/sprite_player_bullet.h"


void init_bullets(BulletPool* pool, uint8_t number_of_bullets, uint8_t tile, uint8_t startingSprite);
void push_bullet_to_pool(BulletPool* pool, Bullet* bullet);
Bullet* get_bullet_from_pool(BulletPool* pool);
uint8_t pool_size(BulletPool* pool);
#endif
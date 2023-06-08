#ifndef BULLET_STRUCT_H
#define BULLET_STRUCT_H

#include <gb/gb.h>
#include <stdbool.h>
#include "position.h"
#include "collider_c.h"

typedef struct BulletPool BulletPool;
typedef struct Bullet Bullet;

//Bullet Struct
struct Bullet{
    Position pos;
    CircleCol collider;
    bool moving;
    uint8_t spriteID;
    uint8_t index;
    Bullet* next;//for the pool
    BulletPool* pool;
};

typedef struct BulletPool{
    Bullet bullets[4];//yikes need to change this maybe later. bullet init isn't safe
    Bullet* firstFree;
    uint8_t freeSize;
}BulletPool;

#endif
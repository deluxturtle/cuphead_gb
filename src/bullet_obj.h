#ifndef BULLET_OBJ_H
#define BULLET_OBJ_H

#include <gb/gb.h>
#include "position.h"
#include "collider_c.h"
#include <stdbool.h>

//This probably shouldn't be duplicated for each bullet so its become a global.
#define BULLET_DMG 1
#define BULLET_RADIUS 4

//Bullet Struct
typedef struct Bullet{
    Position pos;
    CircleCol collider;
    bool moving;
    uint8_t spriteID;
    uint8_t index;
}Bullet;

//Updates bullet position and out of bounds for it self.
void update(struct Bullet* bullet);
//Lets bullet move or freeze it.
void set_moving(struct Bullet* bullet, bool value);

void fire_bullet(struct Bullet* bullet, struct Position* pos);
#endif
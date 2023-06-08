#ifndef BULLET_OBJ_H
#define BULLET_OBJ_H

#include "bullet_struct.h"
#include "bullet_pool.h"

//This probably shouldn't be duplicated for each bullet so its become a global.
#define BULLET_DMG 1
#define BULLET_RADIUS 4

//Updates bullet position and out of bounds for it self.
void bullet_update(struct Bullet* bullet);
//Lets bullet move or freeze it.
void set_moving(struct Bullet* bullet, bool value);

void fire_bullet(struct Bullet* bullet);
#endif
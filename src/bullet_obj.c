#include "bullet_obj.h"

#define BULLETSPEED 1;
//Collider offset so circle collider is centered in the sprite.
#define COLLIDER_POS_X 4
#define COLLIDER_POS_Y 4


void update(struct Bullet* bullet){
    if(!bullet->moving)
        return;
    bullet->pos.x += BULLETSPEED;
    move_sprite(bullet->spriteID, bullet->pos.x, bullet->pos.y);
    
    if(bullet->pos.x > SCREENWIDTH){
        //reset
        bullet->pos.y = 0;
        bullet->moving = false;
    }
}

void set_moving(struct Bullet* bullet, bool value){
    bullet->moving = value;
}

void fire_bullet(struct Bullet* bullet, struct Position* pos){
    bullet->moving = true;
    bullet->pos.x = pos->x;
    bullet->pos.y = pos->y;
}

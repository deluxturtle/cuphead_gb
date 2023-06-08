#include "bullet_obj.h"

#define BULLETSPEED 2;
//Collider offset so circle collider is centered in the sprite.
#define COLLIDER_POS_X 4
#define COLLIDER_POS_Y 4


void bullet_update(struct Bullet* bullet){
    if(!bullet->moving)
        return;
    bullet->pos.x += BULLETSPEED;
    
    
    if(bullet->pos.x > SCREENWIDTH){
        //reset
        bullet->pos.y = 0;
        bullet->moving = false;
        push_bullet_to_pool(bullet->pool, bullet);
    }

    move_sprite(bullet->spriteID, bullet->pos.x, bullet->pos.y);
}

void set_moving(struct Bullet* bullet, bool value){
    bullet->moving = value;
}

void fire_bullet(struct Bullet* bullet){
    bullet->moving = true;
}

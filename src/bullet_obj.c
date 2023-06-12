#include "bullet_obj.h"

#define BULLETSPEED 3;
//Collider offset so circle collider is centered in the sprite.
#define COLLIDER_POS_X 4
#define COLLIDER_POS_Y 4


void bullet_update(struct Bullet* bullet){
    if(!bullet->moving)
        return;

    //If cpu is getting to the limit maybe just make the bullet a 
    //square so we don't have to flip it haha... :/
    if(bullet->bulletDir == RIGHT){
        set_sprite_prop(bullet->spriteID, 0x00);
        bullet->pos.x += BULLETSPEED;
    }
    else{
        set_sprite_prop(bullet->spriteID, S_FLIPX);
        bullet->pos.x -= BULLETSPEED;
    }

    //Bullet loops to the otherside anyway so just leave this here.
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

#include "bullet_obj.h"

#define BULLETSPEED 1;



void update(struct Bullet* bullet){
    if(!bullet->moving)
        return;
    bullet->pos.x += BULLETSPEED;
    if(bullet->pos.x > SCREENWIDTH){
        //reset
        bullet->pos.y = 0;
        bullet->moving = false;
    }
}

void set_moving(struct Bullet* bullet, bool value){
    bullet->moving = value;
}

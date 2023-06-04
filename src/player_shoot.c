#include "player_shoot.h"



void shoot(){
    Bullet *tempBullet = stack_pop(freeBullets);
    if(tempBullet != NULL){
        tempBullet->pos.x = player.pos.x;
        tempBullet->pos.y = player.pos.y;
        set_moving(tempBullet, true);
    }
}
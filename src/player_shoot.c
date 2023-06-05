#include "player_shoot.h"



void shoot(BulletPool* bulletPool, Player* player){
    //Grab a bullet from the pool
    Bullet *tempBullet = stack_pop(bulletPool->freeBullets);

    //make sure we got one else stick a warning bullet up randomly to tell me if somethings wrong.
    if(stack_is_empty(bulletPool->freeBullets) > 0){
        move_sprite(6,60,60);
        return;
    }

    //Then if we got one  pew pew
    if(tempBullet != NULL){
        tempBullet->pos.x = player->pos.x;
        tempBullet->pos.y = player->pos.y;
        fire_bullet(tempBullet, &player->pos);
    }
}
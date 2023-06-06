#include "player_shoot.h"



void shoot(Player* player){

    Bullet* tempBullet;
    //Then if we got one  pew pew
    if(tempBullet != NULL){
        tempBullet->pos.x = player->pos.x;
        tempBullet->pos.y = player->pos.y;
        fire_bullet(&player->bulletPool->bullets[tempBullet->index], &player->pos);
    }
}
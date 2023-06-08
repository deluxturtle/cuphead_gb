#include "player_shoot.h"



void shoot(Player* player){

    Bullet* tempBullet = get_bullet_from_pool(&player->bulletPool);
    uint8_t index = tempBullet->index;
    //Then if we got one  pew pew
    if(tempBullet != NULL){
        tempBullet->pos.x = player->pos.x;
        tempBullet->pos.y = player->pos.y;
        fire_bullet(&player->bulletPool.bullets[index]);
    }
}
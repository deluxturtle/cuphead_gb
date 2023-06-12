#include "player_shoot.h"

#define SHOOT_OFFSET_Y 3
#define SHOOT_OFFSET_FLIP_X 12

void shoot(Player* player){
    if(!player->jumping)
        player->animationState.animation = FIRE;
    
    if(player->fireDelay > 0)
        return;
    
    Bullet* tempBullet = get_bullet_from_pool(&player->bulletPool);
    uint8_t index = tempBullet->index;
    //Then if we got one  pew pew
    if(tempBullet != NULL){
        if(player->facingDirection == LEFT)
            tempBullet->pos.x = player->pos.x - SHOOT_OFFSET_FLIP_X;
        else
            tempBullet->pos.x = player->pos.x;

        tempBullet->pos.y = player->pos.y - SHOOT_OFFSET_Y;
        tempBullet->bulletDir = player->facingDirection;
        fire_bullet(&player->bulletPool.bullets[index]);
        player->fireDelay = FIRE_RATE;
    }
}
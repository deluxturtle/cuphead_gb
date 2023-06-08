#include "bullet_pool.h"
/**
 * The bullet spawner and pool manager :)
*/




//Initializes all bullets and puts them in a pool
//Just make sure to set sprite tiles for your sprite before.
void init_bullets(BulletPool* pool, uint8_t number_of_bullets, uint8_t tile, uint8_t startingSprite){
    
    pool->firstFree = NULL;

    for(uint8_t i = 0; i < number_of_bullets; i++){
        pool->bullets[i].pos.x = 8*i;
        pool->bullets[i].pos.y = 0;
        pool->bullets[i].collider.pos = &pool->bullets[i].pos;
        pool->bullets[i].spriteID = startingSprite+i;
        pool->bullets[i].index = i;
        pool->bullets[i].pool = pool;
        set_sprite_tile(pool->bullets[i].spriteID, tile);

        //add to free bullets to use
        push_bullet_to_pool(pool, &pool->bullets[i]);

    }

}


void push_bullet_to_pool(BulletPool* pool, Bullet* bullet){
    
    bullet->next = pool->firstFree;

    pool->firstFree = bullet;
    pool->freeSize++;
}

Bullet* get_bullet_from_pool(BulletPool* pool){
    if(pool->freeSize < 1){
        return NULL;
    }

    Bullet* tempBullet = pool->firstFree;

    pool->firstFree = pool->firstFree->next;
    pool->freeSize--;

    return tempBullet;
}

uint8_t pool_size(BulletPool* pool){
    return pool->freeSize;
}
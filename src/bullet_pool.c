#include "bullet_pool.h"
/**
 * The bullet spawner and pool manager :)
*/




//Initializes all bullets and puts them in a pool
//Just make sure to set sprite tiles for your sprite before.
void init_bullets(BulletPool* pool, uint8_t number_of_bullets, uint8_t tile, uint8_t startingSprite){
    //Create the bullet pool
    pool->freeBullets = stack_create();
    
    for(uint8_t i = 0; i < number_of_bullets; i++){
        pool->bullets[i].pos.x = 0;
        pool->bullets[i].pos.y = 0;
        pool->bullets[i].collider.pos = &pool->bullets[i].pos;
        pool->bullets[i].spriteID = startingSprite + i;
        stack_push(pool->freeBullets, &pool->bullets[i]);
        set_sprite_tile(pool->bullets[i].spriteID, tile);
    }

}
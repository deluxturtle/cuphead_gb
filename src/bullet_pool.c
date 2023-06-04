#include "bullet_pool.h"
/**
 * The bullet spawner and pool manager :)
*/

//Collider offset so circle collider is centered in the sprite.
#define COLLIDER_POS_X 4
#define COLLIDER_POS_Y 4


Bullet bullets[4];
stack *freeBullets;


//Initializes all bullets and puts them in a pool
void init_bullets(){

    //Set sprite Data
    set_sprite_data(50, 1, sprite_player_bullet_tile);

    //Create the bullet pool
    freeBullets = stack_create();
    for(uint8_t i = 0; i < MAX_BULLETS; i++){
        bullets[i].pos.x = 0;
        bullets[i].pos.y = 0;
        bullets[i].collider.pos = &bullets[i].pos;
        stack_push(freeBullets, &bullets[i]);

    }

    //initilize bullets
    uint8_t i;

}
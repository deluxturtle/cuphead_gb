/**
 * @file player_sprites.h
 * @author deluxturtle
 * @brief 
 * @version 0.1
 * @date 2021-06-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef PLAYER_SPRITES_H
#define PLAYER_SPRITES_H

#include <gb/gb.h>
#include <gb/metasprites.h>
#include "player_base.h"
#include "../res/sprite_player_idle.h"
#include "../res/sprite_player_fire.h"
#include "../res/sprite_player_jump.h"




/**
 * @brief Master list of animations
 * If needing to add more this is the first thing to add to.
 * 
 */
typedef enum AnimState{
    IDLE,
    FIRE,
    JUMP
}AnimState;

extern AnimState animState;

void player_reset_anim();

/**
 * @brief Creates a list of animations to change animations on the fly.
 * 
 */
void player_init_anim();

void player_setanimshoot();

void player_update_sprite();


#endif
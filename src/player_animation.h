/**
 * @file player_animation.h
 * @author deluxturtle
 * @brief 
 * @version 0.1
 * @date 2021-06-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef PLAYER_ANIMATION_H
#define PLAYER_ANIMATION_H

#include "player_base.h"
#include "../res/sprite_player_idle.h"
#include "../res/sprite_player_fire.h"
#include "../res/sprite_player_jump.h"


void player_reset_anim(Player* player);

/**
 * @brief Creates a list of animations to change animations on the fly.
 * 
 */
void player_init_anim(Player* player);

void player_setanimshoot(Player* player);

void player_update_animation(Player* player);


#endif
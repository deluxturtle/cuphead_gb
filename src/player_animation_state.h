#ifndef PLAYER_ANIMATION_STATE_H
#define PLAYER_ANIMATION_STATE_H
#include <gb/gb.h>
#include <gb/metasprites.h>
#include "player_base.h"

/**
 * @brief Master list of animations
 * If needing to add more this is the first thing to add to.
 * 
 */
typedef enum Animation{
    IDLE,
    FIRE,
    JUMP
}Animation;

typedef struct AnimationState{
    Animation animation;
    Animation prevAnimation;
    metasprite_t *const *animations[4];
    uint8_t* anim_frames;
    uint8_t cur_frame;
    uint8_t animation_tile;
}AnimationState;

#endif
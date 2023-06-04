#include <gb/gb.h>
#include "bullet_obj.h"
#include "stack.h"
#include "../res/sprite_player_bullet.h"

static const uint8_t MAX_BULLETS = 4;

extern stack *freeBullets;
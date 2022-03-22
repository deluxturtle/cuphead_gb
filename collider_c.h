#ifndef COLLIDER_C_H
#define COLLIDER_C_H
#include <gb/gb.h>
#include "position.h"

/**
 * @brief Circle collider struct
 * 
 */
typedef struct CircleCol{
    uint8_t radius;
    Position *pos;//so i can just point it to an object's position.
}CircleCol;

/**
 * @brief Checks if the two circle colliders are overlapping.
 * Used for bullets.
 * 
 * @param a collider a
 * @param b collider b to check against
 * @param result 1 if overlap. -1 if not. 0 if touching
 */
void collision_check(CircleCol *a, CircleCol *b, uint8_t *result);

#endif
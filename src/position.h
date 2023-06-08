#ifndef POSITION_H
#define POSITION_H

#include <gb/gb.h>

typedef struct Position{
    uint8_t x;
    uint8_t y;
}Position;

typedef enum Facing{
    LEFT,
    RIGHT
}Facing;

#endif
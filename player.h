#ifndef PLAYER_H_ 
#define PLAYER_H_ 

#include <ncurses.h>
#include <stdlib.h>
#include <stdint.h>
#include "geometry.h"
#include "room.h"


struct player
{
    point_t pos;
    uint16_t hp;
    uint8_t level;
    char model;
};

typedef struct player player_t;

player_t * new_player(uint32_t x, uint32_t y);
void draw_player(player_t *p);
void move_player(player_t *p, room_t *r, uint32_t dir);
void attempt_open_door(player_t *p, room_t *r);
#endif

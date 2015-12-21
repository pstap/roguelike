#ifndef ROOM_H_
#define ROOM_H_

#include <ncurses.h>
#include <stdlib.h>
#include <stdint.h>
#include "object.h"

/*
 *
 * Map stores static objects (walls, doors, etc.)
 * Entities will store dynamic objects, etc.
 *
*/

struct room
{
    uint32_t width;
    uint32_t height;
    object_t **map;
};

typedef struct room room_t;

room_t new_room(uint32_t width, uint32_t height);
void destroy_room(room_t* r);
void draw_room(room_t* r);
void draw_room_with_lighting(room_t* r);
void clear_lighting(room_t* r);
void add_walls(room_t* r);
object_t * object_at(uint32_t x, uint32_t y, room_t* r);
void add_new_object_at(uint32_t x, uint32_t y, object_t o, room_t* r);
void setup_test_room(room_t* main_room);

#endif

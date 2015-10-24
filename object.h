#ifndef OBJECT_H_ 
#define OBJECT_H_ 

// Objects only exist in the physical world
// Items are to be implemented
// Items may appear in the world, but will take up no physical space
// Items will be put in a linked list stored in the room

// Each object has an type (basically an ID)
#define ERROR_ID -1
#define AIR_ID    0
#define WALL_ID   1
#define DOOR_ID   2

// List of object properties
#define PROP_SOLID   0x01
#define PROP_VISIBLE 0x02
#define PROP_OPEN    0x04
#define PROP_LIT     0x08

#include <ncurses.h>
#include <stdlib.h>
#include <stdint.h>
#include "geometry.h"

struct object
{
    int type;
    char model;
    uint32_t properties;
};

typedef struct object object_t;

void draw_object(object_t *o, uint32_t x, uint32_t y);
void draw_object_with_lighting(object_t *o, uint32_t x, uint32_t y);
object_t new_air();
object_t new_wall();
object_t new_door(uint8_t open);
void open_door(object_t *o);
object_t new_obj_by_type(int type);
int has_property(int property, object_t *o);
void set_property(int property, object_t *o);
void unset_property(int property, object_t *o);
int is_solid(object_t *o);
int is_open(object_t *o);
int is_lit(object_t *o);
int is_of_type(object_t *o, int t);
#endif

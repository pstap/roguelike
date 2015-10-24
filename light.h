#ifndef LIGHT_H_ 
#define LIGHT_H_ 

#include "room.h"
#include "object.h"

void clear_lighting(room_t *r);
void emit_light(uint32_t x, uint32_t y, uint32_t radius, room_t *r);
void cast_ray(uint32_t x, uint32_t y, int32_t dx, int32_t dy, uint32_t length, room_t *r);
void exp_cast(uint32_t x, uint32_t y, uint32_t radius, room_t *r);
#endif

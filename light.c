#include "light.h"

void clear_lighting(room_t* r)
{
    int i;
	int j;
	
    for(i = 0; i < r->height; i++)
    {
        for(j = 0; j < r->width; j++)
        {
            unset_property(PROP_LIT, &r->map[i][j]);
        }
    }
}

void emit_light(uint32_t x, uint32_t y, uint32_t radius, room_t* r)
{
    object_t* o;
    int i;

    for(i = 1; i <= radius; i++)
    {
        if((o = object_at(x - i, y, r)) != NULL)
            set_property(PROP_LIT, o);
        if((o = object_at(x + i, y, r)) != NULL)
            set_property(PROP_LIT, o);
        if((o = object_at(x, y + i, r)) != NULL)
            set_property(PROP_LIT, o);
        if((o = object_at(x, y - i, r)) != NULL)
            set_property(PROP_LIT, o);
        if((o = object_at(x - i, y - i, r)) != NULL)
            set_property(PROP_LIT, o);
        if((o = object_at(x + i, y - i, r)) != NULL)
            set_property(PROP_LIT, o);
        if((o = object_at(x - i, y + i, r)) != NULL)
            set_property(PROP_LIT, o); 
        if((o = object_at(x + i, y - i, r)) != NULL)
            set_property(PROP_LIT, o);
        if((o = object_at(x + i, y + i, r)) != NULL)
            set_property(PROP_LIT, o);
    }
}


// Rays which cast shadows
void cast_ray(uint32_t x, uint32_t y, int32_t dx, int32_t dy, uint32_t length, room_t* r)
{
    int not_hit_solid = 1;
    uint32_t current_x = x;
    uint32_t current_y = y;
    object_t *o = NULL;

    int i = 1;

    while(not_hit_solid && i <= length)
    {
        o = object_at(current_x, current_y, r);
        set_property(PROP_LIT, o);

        if(has_property(PROP_SOLID, o))
            not_hit_solid = 0;

        current_x += dx;
        current_y += dy;
        i++;
    }
}

void exp_cast(uint32_t x, uint32_t y, uint32_t radius, room_t* r)
{
    // upwards
    cast_ray(x, y, +0, -1, radius, r);
    // downwards
    cast_ray(x, y, +0, +1, radius, r);
    // left
    cast_ray(x, y, -1, +0, radius, r);
    // right
    cast_ray(x, y, +1, +0, radius, r);
}

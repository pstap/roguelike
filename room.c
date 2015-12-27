#include "room.h"


// Generate a new room, allocating enough space
room_t new_room(uint32_t width, uint32_t height)
{
    room_t temp;
    temp.width = width;
    temp.height = height;

    temp.map = malloc(sizeof(object_t *) * height);

    int i, j;
    for(i = 0; i < height; i++)
    {
        temp.map[i] = malloc(sizeof(object_t) * width);
    }


    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            temp.map[i][j] = new_air();
        }
    }

    return temp;
}

// Free all stored memory
void destroy_room(room_t* r)
{
    int i;

    for(i = 0; i < r->height; i++)
    {
		free(r->map[i]);
    }
}

// Go through and draw each object in a room
void draw_room(room_t* r)
{   
    int i, j;
    for(i = 0; i < r->height; i++)
    {
        for(j = 0; j < r->width; j++)
        {
            draw_object(&r->map[i][j], j, i);   
        }
    }
}

// (Deprecated)
void draw_room_with_lighting(room_t* r)
{   
    int i, j;
    for(i = 0; i < r->height; i++)
    {
        for(j = 0; j < r->width; j++)
        {
            draw_object_with_lighting(&r->map[i][j], j, i);   
        }
    }
}

// Draw walls around the the border of a r
void add_walls(room_t* r)
{
    int i;
    int j;
    for(i = 0; i < r->height; i++)
    {
        for(j = 0; j < r->width; j++)
        {
            if(i == 0 
               || i == (r->height - 1)
               || j == 0 
               || j == (r->width - 1))
            {
                r->map[i][j] = new_wall();
            }
        }
    }
}

// Return the object at a given index
object_t * object_at(uint32_t x, uint32_t y, room_t* r)
{
    if(x >= r->width || y >= r->height)
        return NULL;
    else
        return &r->map[y][x];
}

// Add a new object at a particular position
void add_new_object_at(uint32_t x, uint32_t y, object_t o, room_t* r)
{
    r->map[y][x] = o;
}

// Just setup a test room
void setup_test_room(room_t* main_room)
{
    add_walls(main_room);
    add_new_object_at(1, 3, new_wall(), main_room);
    add_new_object_at(3, 1, new_wall(), main_room);
    add_new_object_at(2, 3, new_wall(), main_room);
    add_new_object_at(3, 3, new_wall(), main_room);
    add_new_object_at(3, 2, new_door(0), main_room);
    add_new_object_at(9, 17, new_door(0), main_room);
}

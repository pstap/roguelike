#include "object.h"

// Draw an object given a particular X and Y
void draw_object(object_t* o, uint32_t x, uint32_t y)
{
    switch(o->type)
    {
        case AIR_ID: 
            mvaddch(y, x, ' ');
            break;
        
        case WALL_ID:
            mvaddch(y, x, ACS_BLOCK);
            break;

        default:
            mvaddch(y, x, o->model);
            break;
    }
}

// TODO Either fix lighting or just give up
void draw_object_with_lighting(object_t* o, uint32_t x, uint32_t y)
{
    if(is_lit(o))
    {
        draw_object(o, x, y);
    }
}

// Return a new air object
object_t new_air()
{
    object_t temp;
    temp.type  = AIR_ID;
    temp.model = ' ';
    temp.properties = 0;

    return temp;
}

// Return a new wall object
object_t new_wall()
{
    object_t temp;
    temp.type  = WALL_ID;
    temp.model = '?';
    temp.properties = PROP_SOLID | PROP_VISIBLE;

    return temp;

}

// Return a new door object
object_t new_door(uint8_t open)
{
    object_t temp;
    temp.type  = DOOR_ID;

    // Declare it open
    if(open)
    {
        temp.properties = PROP_VISIBLE | PROP_OPEN;
        temp.model = '.';
    }
    else
    { 
        temp.properties = PROP_SOLID | PROP_VISIBLE;
        temp.model = 'D';
    }

    return temp;
}

// Opens a door
void open_door(object_t* o)
{
    if(o->type == DOOR_ID)
    {
        // Open
        if(is_open(o))
        {
            unset_property(PROP_OPEN, o);
            set_property(PROP_SOLID, o);
            o->model = 'D';
        }
        // Closed
        else
        {
            set_property(PROP_OPEN, o);
            unset_property(PROP_SOLID, o);
            o->model = '.';
        }
    }
}

object_t new_obj_by_type(int type)
{
	object_t error;
	error.type = ERROR_ID;
    switch(type)
    {
        case AIR_ID:
            return new_air();
            break;
        
        case WALL_ID:
            return new_wall();
            break;
       
        case DOOR_ID:
            return new_door(0);
            break;

        default:
            return error;
    }
}

int has_property(int property, object_t* o)
{
    if(o->properties & property)
	{
        return 1;
	}
    else
	{
        return 0;
	}
}

void set_property(int property, object_t* o)
{
    o->properties = o->properties | property;
}

void unset_property(int property, object_t* o)
{
    o->properties = o->properties & ~property;
}

int is_solid(object_t* o)
{
    if(o->properties & PROP_SOLID)
	{
        return 1;
	}
    else
	{	   
        return 0;
	}
}

int is_open(object_t* o)
{
    if(o->properties & PROP_OPEN)
	{		
        return 1;
	}
    else
	{
        return 0;
	}
}

int is_lit(object_t* o)
{
    if(o->properties & PROP_LIT)
	{
        return 1;
	}
    else
	{
        return 0;
	}
}

int is_of_type(object_t* o, int t)
{
    if(o->type == t)
	{
        return 1;
	}
    else
	{
        return 0;
	}
}

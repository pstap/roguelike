#include "player.h"


player_t new_player(uint32_t x, uint32_t y)
{
    player_t temp;
    temp.pos.x = x;
    temp.pos.y = y;
    temp.model = '@';

    return temp;
}

void draw_player(player_t *p)
{
    mvaddch(p->pos.y, p->pos.x, p->model);
}

void move_player(player_t *p, room_t *r, uint32_t dir)
{
    // 0 = north, 1 = south, 2 = east, 3 = west
    switch(dir)
    {
        case 0:
            if(!is_solid(&r->map[p->pos.y - 1][p->pos.x]))
                p->pos.y -= 1;
            break;

        case 1:
            if(!is_solid(&r->map[p->pos.y + 1][p->pos.x]))
                p->pos.y += 1;
            break;

        case 2:
            if(!is_solid(&r->map[p->pos.y][p->pos.x + 1]))
                p->pos.x += 1;
            break;

        case 3:
            if(!is_solid(&r->map[p->pos.y][p->pos.x - 1]))
                p->pos.x -= 1;
            break;

        default:
            break;
    }
}

// Attempts to open a door if present, return 1 on succesful open
int attempt_open_door(player_t* p, room_t* r)
{
    object_t* door = NULL;
    
    if(is_of_type(object_at(p->pos.x - 1, p->pos.y, r), DOOR_ID))
        door = object_at(p->pos.x - 1, p->pos.y, r);

    else if(is_of_type(object_at(p->pos.x + 1, p->pos.y, r), DOOR_ID))
        door = object_at(p->pos.x + 1, p->pos.y, r);

    else if(is_of_type(object_at(p->pos.x, p->pos.y - 1, r), DOOR_ID))
        door = object_at(p->pos.x, p->pos.y - 1, r);

    else if(is_of_type(object_at(p->pos.x, p->pos.y + 1, r), DOOR_ID))
        door = object_at(p->pos.x, p->pos.y + 1, r);

    if(door != NULL)
	{
        open_door(door);
		return 1;
	}
	else
	{
		return 0;
	}
}

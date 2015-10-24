#include <ncurses.h>
#include <stdint.h>

#include "object.h"
#include "light.h"
#include "room.h"
#include "player.h"
#include "olist.h"

// Debugging settings
uint8_t DBG_SHOW_POS = 1;
uint8_t DBG_CALC_LIGHTING = 0;

void setup()
{
    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
}

void cleanup()
{
    endwin();
}

// Returns 0 for quit, 1 for anything else
int handle_input(char c, player_t *p, room_t *r)
{
    if(c == ',')
        move_player(p, r, 0);
    else if(c == 'o')
        move_player(p, r, 1);
    else if(c == 'e')
        move_player(p, r, 2);
    else if(c == 'a')
        move_player(p, r, 3);
    if(c == 'q')
        return 0;
    if(c == 'd')
        attempt_open_door(p, r);
    if(c == 'l')
    {
        if(DBG_CALC_LIGHTING)
            DBG_CALC_LIGHTING = 0;
        else
            DBG_CALC_LIGHTING = 1;
    }

    return 1;
}



inline void setup_room(room_t *main_room)
{
    add_walls(main_room);
    add_new_object_at(1, 3, new_wall(), main_room);
    add_new_object_at(3, 1, new_wall(), main_room);
    add_new_object_at(2, 3, new_wall(), main_room);
    add_new_object_at(3, 3, new_wall(), main_room);
    add_new_object_at(3, 2, new_door(0), main_room);
    add_new_object_at(9, 17, new_door(0), main_room);
}

int main(int argc, char *argv[])
{
    setup();
    
    player_t *p = new_player(0, 0);
    room_t main_room = new_room(20, 20);

    setup_room(&main_room);

    if(DBG_SHOW_POS)
    {
        mvprintw(21, 0, "Player x: %d", p->pos.x);
        mvprintw(22, 0, "Player y: %d", p->pos.y);
    }

    draw_room(&main_room);
    draw_player(p);
    
    char c;
    int run = 1;

    
//    clear_lighting(&main_room);

    while(run)
    {
	mvprintw(23,0, "Ready for input");
        c = getch();
        run = handle_input(c, p, &main_room);

        erase();
    
        if(DBG_CALC_LIGHTING)
        {
            //clear_lighting(&main_room);
            //emit_ligxht(p->pos.x, p->pos.y, 4, main_room);
            //exp_cast(p->pos.x, p->pos.y, 6, &main_room);
            //draw_room_with_lighting(&main_room);
        }
        else
        { 
            draw_room(&main_room);
        }

        draw_player(p);

        if(DBG_SHOW_POS)
        {
            mvprintw(21, 0, "Player x: %d", p->pos.x);
            mvprintw(22, 0, "Player y: %d", p->pos.y);
        }

        refresh();
    }

    cleanup();
    destroy_room(&main_room);
    free(p);

    return 0;
}


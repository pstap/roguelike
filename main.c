#include <ncurses.h>
#include <stdint.h>

#include "object.h"
#include "light.h"
#include "room.h"
#include "player.h"
#include "ui.h"
#include "input.h"


void cleanup()
{
    endwin();
}

int main(int argc, char* argv[])
{
    ui_setup();
	
    player_t p = new_player(1, 1, "hi");
    room_t main_room = new_room(20, 20);
	uint8_t game_mode = 0;

	ui_settings_t ui;
	ui.display_pos = 1;

    setup_test_room(&main_room);
	render_frame(&ui, game_mode, &p, &main_room);
    
    char c;
    int run = 1;

	prompt_for_string(0, 21, "Enter name: ", p.name);
	
	mvprintw(1, 21, "Name: %s", p.name);
	
    while(run)
    {
        c = getch();
        run = handle_input(c, &ui, &p, &main_room);

		render_frame(&ui, game_mode, &p, &main_room);
    }

    cleanup();
    destroy_room(&main_room);

    return 0;
}


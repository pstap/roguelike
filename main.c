#include <ncurses.h>
#include <stdint.h>

#include "object.h"
#include "light.h"
#include "room.h"
#include "player.h"
#include "ui.h"
#include "input.h"

int main(int argc, char* argv[])
{
	// Sets up NCurses for game mode
	// UI settings for if paused, etc.
	ui_settings_t ui;
    ui_setup(&ui);
	// Set debugging for showing position
	ui.display_pos = 1;

	// Only a single player object
    player_t p = new_player(1, 1, "hi");

	// New 20x20 room
    room_t main_room = new_room(20, 20);

	// Add some walls and doors to the test room
    setup_test_room(&main_room);

	// Stored temporarily here until game modes changes
	uint8_t game_mode = 0;
	
	// Render a single frame
	render_frame(&ui, game_mode, &p, &main_room);

	// This is dumb, get rid of this
    char c;
    int run = 1;

	// Test string prompting, get the player's name.
	prompt_for_string(0, 21, "Enter name: ", p.name);

	mvprintw(1, 21, "Name: %s", p.name);
	mvprintw(2, 21, "Term window size: %dx%d", ui.width, ui.height);

	timeout(-1);
	getch();
	timeout(17);

	// Main gameloop
	// Get a character, handle the input, render the new frame
    while(run)
    {
        c = getch();
        run = handle_input(c, &ui, &p, &main_room);
		render_frame(&ui, game_mode, &p, &main_room);
    }

	// Clean stuff up
	endwin();
    destroy_room(&main_room);

    return 0;
}


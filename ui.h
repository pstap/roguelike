#ifndef UI_H
#define UI_H

#include <ncurses.h>
#include <stdint.h>

#include "player.h"
#include "room.h"

struct ui_settings
{
	uint32_t height;
	uint32_t width;
	uint8_t display_pos;
	WINDOW* main_win;
	WINDOW* map_pane;
	WINDOW* info_pane;
	WINDOW* status_pane;
};

typedef struct ui_settings ui_settings_t;

// Blocking
void prompt_for_string(uint16_t y, uint16_t x, char* prompt, char* buf);
void render_frame(ui_settings_t* u, uint8_t mode, player_t* p, room_t* r);
void ui_setup(ui_settings_t* ui_ptr);

#endif

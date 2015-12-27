#include "ui.h"

static uint32_t strlen(char* str)
{
	uint32_t i;
	for(i = 0; str[i] != '\0'; i++);
	return i;
}

void prompt_for_string(uint16_t y, uint16_t x, char* prompt, char* buf)
{
	uint32_t len;
	char c;
	int i = 0;
	
	mvprintw(y, x, prompt);

	curs_set(1);
	timeout(-1);

	len = strlen(prompt);
	
	while((c = getch()) != '\n' && i < 100)
	{
		if(c == 8 || c == 127)
		{
			if(i != 0)
			{
				i -= 1;
			}
			mvaddch(0, x + len + i, ' ');
			move(0, x + len + i);
		}
		else
		{
			buf[i] = c;
			mvaddch(0, x + len  + i, c);
			i++;
		}
		refresh();
	}
	curs_set(0);
	timeout(17);
}

void render_frame(ui_settings_t* u, uint8_t mode, player_t* p, room_t* r)
{
	erase();
	
	draw_room(r);
	draw_player(p);

	if(u->display_pos)
	{
		mvprintw(21, 0, "Player x: %d", p->pos.x);
		mvprintw(22, 0, "Player y: %d", p->pos.y);
	}

	refresh();
}

void ui_setup(ui_settings_t* ui_ptr)
{
    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
	timeout(17);
	getmaxyx(stdscr, ui_ptr->height, ui_ptr->width);
}

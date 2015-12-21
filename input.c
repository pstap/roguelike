#include "input.h"

// Returns 0 for quit, 1 for anything else
int handle_input(char c, ui_settings_t* ui, player_t* p, room_t* r)
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
	if(c == 'p')
	{
		if(ui->display_pos)
		{
			ui->display_pos = 0;
		}
		else
		{
			ui->display_pos = 1;
		}
	}

    return 1;
}

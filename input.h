#ifndef INPUT_H
#define INPUT_H

/*
 * input.h
 * handle keypresses
 *
 */


#include "player.h"
#include "room.h"
#include "ui.h"

int handle_input(char c, ui_settings_t* ui, player_t* p, room_t* r);

#endif

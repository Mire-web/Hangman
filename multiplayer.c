#include "main.h"

/**
 * single_player - single player mode
 *
 */

void single_player(int mode)
{
	if (mode == 0)
	{
		Home();
		return;
	}
	mode == 1 ? easy_mode() : mode == 2 ? medium_mode()	: hard_mode();
}

void multiplayer()
{
}


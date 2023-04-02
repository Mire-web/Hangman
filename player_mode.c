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
	char player_one[10];
	char player_two[10];
	printf("\tPlayer One username(Can't be blank): ");
	scanf("%s", player_one);
	getchar();
	printf("\tPlayer Two username(Can't be blank): ");
	scanf("%s", player_two);
	getchar();
	printf("\n\t\t%s vs %s\n", player_one, player_two);
}


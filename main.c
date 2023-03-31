#include "main.h"

/**
 * Home - Home screen for mode selection
 *
 * Return: User selected gameMode;
 */

int Home()
{
	int gameMode;
	printf("\t\t1. Single Player.\n\t\t2. Multiplayer\n");
	printf("\tSelect Game Mode: ");
	scanf("%d", &gameMode);
	while (gameMode > 2 || gameMode < 1)
	{
		printf("\tOmo look availiable options for menu na!!\n");
		printf("\tSelect Game Mode: ");
		scanf("%d", &gameMode);
	}
	gameMode == 1 ? single_player(mode_select()) : multiplayer();
	return (gameMode);
}

int main(void)
{
	printf("\t**MANGMAN************************************\n");
	printf("\t*******************MANGMAN*******************\n");
	printf("\t************************************MANGMAN**\n\n");
	printf("%d\n", Home());
	return (0);
}
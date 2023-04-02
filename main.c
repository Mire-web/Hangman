#include "main.h"

/**
 * Home - Home screen for mode selection
 *
 * Return: User selected gameMode;
 */

int Home()
{
	int gameMode;
	printf("\n\t\t1. Single Player.\n\t\t2. Multiplayer\n\t\t3. Quit\n");
	printf("\tSelect Game Mode: ");
	scanf("%d", &gameMode);
	while (gameMode > 3 || gameMode < 1)
	{
		printf("\n\tWrong selection, Try again!!\n");
		printf("\tSelect Game Mode: ");
		scanf("%d", &gameMode);
	}
	gameMode == 1 ? single_player(mode_select()) : gameMode == 2 ? multiplayer() : exit(98);
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
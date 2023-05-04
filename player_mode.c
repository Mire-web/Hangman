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
	int player_one_score = 0;
	int player_two_score = 0;
	printf("\tPlayer One username(Can't be blank): ");
	scanf("%s", player_one);
	getchar();
	printf("\tPlayer Two username(Can't be blank): ");
	scanf("%s", player_two);
	getchar();
	printf("\n\t\t%s vs %s\n", player_one, player_two);
	printf("\t\t%d : %d\n", player_one_score, player_two_score);
	printf("\t\t***********Instructions***********\n\t**Opposing player has to look away while the other types\n");
	player_one_turn(&player_one_score);
}

void player_one_turn(int __attribute__((unused)) *score)
{
	char word[10];
	int __attribute__((unused)) i;
	char __attribute__((unused)) c[5];
	char *omitted = NULL;

	printf("\tEnter a word(10 letters max): ");
	scanf("%s",word);
	omitted = omit_letter(word);
	system("clear");
	printf("\t%s\n", omitted);
	printf("\n\t⚠ Only input missing letters in the order they should appear\n\tℹ enter 0 to quit\n");
	printf("\tAnswer: ");
	scanf("%s", c);
	getchar();
}

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
	mode == 1 ? easy_mode() : mode == 2 ? medium_mode(): hard_mode();
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
	player_two_turn(&player_two_score);
}

void player_one_turn(int __attribute__((unused)) * score)
{
	char word[10];
	int __attribute__((unused)) i, result;
	char __attribute__((unused)) c[5];
	char *omitted = NULL;
	char *replaced = NULL;

	printf("\tPlayer one\n");

	printf("\tEnter a word(10 letters max): ");
	scanf("%s", word);
	omitted = omit_letter(word);
	system("clear");
	printf("\t%s\n", omitted);
	printf("\n\t⚠ Only input missing letters in the order they should appear\n\tℹ enter 0 to quit\n");
	printf("\tAnswer: ");
	scanf("%s", c);
	getchar();
	replaced = replace_word(omitted, c);
	if (!replaced)
	{
		free(replaced);
		exit(EXIT_FAILURE);
	}
	/*result = decision(replaced, word);*/
	if (decision(replaced, word) == -1)
	{
		printf("\tWrong\n");
	}
	else
	printf("\tCorrect\n");
}

void player_two_turn(int __attribute__((unused)) * score)
{
	char word[10];
	int __attribute__((unused)) i;
	char __attribute__((unused)) c[5];
	char *omitted = NULL;

	printf("\tPlayer two\n");

	printf("\tEnter a word(10 letters max): ");
	scanf("%s", word);
	omitted = omit_letter(word);
	system("clear");
	printf("\t%s\n", omitted);
	printf("\n\t⚠ Only input missing letters in the order they should appear\n\tℹ enter 0 to quit\n");
	printf("\tAnswer: ");
	scanf("%s", c);
	getchar();
}

/**
 * replace_word - Replace missing words with user input
 *
 * @word: Omitted text
 * @input: User input
 * Return: pointer to the full word or NULL if malloc fails
 */

char *replace_word(char *word, char *input)
{
	char *replaced = malloc(sizeof(char) * strlen(word));
	int i, j = 0;
	if (!replaced)
	{
		free(replaced);
		return (NULL);
	}
	for (i = 0; word[i] != '\0'; i++)
	{
		if (word[i] == '_')
		{
			replaced[i] = input[j];
			j++;
		}
		else
			replaced[i] = word[i];
	}
	return (replaced);
}

int decision(char *ans, char *ques)
{
	int i;
	for (i = 0; ans[i]; i++)
	{
		if (ans[i] != ques[i] && ans[i] && ques[i])
		{
			return (-1);
		}
	}
	return (0);
}
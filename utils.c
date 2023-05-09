#include "main.h"


int Player_one_score = 0;
int Player_two_score = 0;
int total = 0;

/**
 * mode_select - select difficulty
 *
 * @Return: int
 */
int mode_select()
{
	int difficulty;
	printf("\n\t\t**********DIFFICULTY**********\n");
	printf("\n\t\t1. Easy\n\t\t2. Medium\n\t\t3. Hard\n\t\t0. Back\n");
	printf("\n\tSelect Difficulty: ");
	scanf("%d", &difficulty);
	getchar();
	while (difficulty > 3 || difficulty < 0)
	{
		printf("\n\tWrong selection Try again!!\n");
		printf("\n\t\t1. Easy\n\t\t2. Medium\n\t\t3. Hard\n\t\t0. Back\n");
		printf("\n\tSelect Difficulty: ");
		scanf("%d", &difficulty);
		getchar();
	}

	if (difficulty == 0)
	{
		Home();
		return (0);
	}
	return (difficulty);
}

/**
 * update_score - Update player Player_one_score if correct
 *
 * @Player_one_score: Player Score
 */

void update_score(int *score)
{
	++*score;
}

/********************SINGLE PLAYER UTILITY FUNCTIONS***********************/

/**
 * easy_mode - Function for easy gameplay
 *
 */
void easy_mode()
{
	int i;
	char word[5];
	char *replaced = NULL;
	char user[2];
	char *omitted;
	int mistake = 0;
	srand(time(NULL));
	strcpy(word, &four_word[rand() % 50][0]);
	omitted = omit_letter(word);
	printf("\n\t⚠ Only input missing letters in the order they should appear\n\tℹ enter 0 to quit\n");
	printf("\n\tComplete: %s\n", omitted);
	printf("\tAnswer: ");
	scanf("%s", user);
	getchar();
	if (user[0] == '0')
	{
		printf("\t\tYou scored: %d/%d\n", Player_one_score, total);
		single_player(mode_select());
		return;
	}
	replaced = replace_word(omitted, user);
	if (!replaced)
	{
		free(replaced);
		exit(EXIT_FAILURE);
	}
	for (i = 0; replaced[i] != '\0'; i++)
	{
		if (replaced[i] != word[i] && replaced[i] & word[i])
		{
			printf("\tWrong\n\n\tScore: %d/%d\n", Player_one_score, ++total);
			mistake++;
			break;
		}
	}
	if (mistake == 0)
	{
		update_score(&Player_one_score);
		printf("\tCorrect\n\n\tScore: %d/%d\n", Player_one_score, ++total);
	}
	free(replaced);
	easy_mode();
}

/**
 * medium_mode - Gameplay a little harder than easy mode
 *
 */

void medium_mode()
{
	int i;
	char word[6];
	char *replaced = NULL;
	char user[3];
	char *omitted;
	int mistake = 0;
	int j = 0;
	srand(time(NULL));
	strcpy(word, &five_word[rand() % 50][0]);
	omitted = omit_letter(word);
	printf("\n\t⚠ Only input missing letters in the order they should appear\n\tℹ enter 0 to quit\n");
	printf("\n\tComplete: %s\n", omitted);
	printf("\tAnswer: ");
	scanf("%s", user);
	getchar();
	if (user[0] == '0')
	{
		printf("\t\tYou scored: %d/%d\n", Player_one_score, total);
		single_player(mode_select());
		return;
	}
	replaced = replace_word(omitted, user);
	if (!replaced)
	{
		free(replaced);
		exit(EXIT_FAILURE);
	}
	for (i = 0; replaced[i] != '\0'; i++)
	{
		if (replaced[i] != word[i] && replaced[i] & word[i])
		{
			printf("\tWrong\n");
			printf("\tScore: %d/%d\n", Player_one_score, ++total);
			mistake++;
			break;
		}
	}
	if (mistake == 0)
	{
		printf("\tCorrect\n");
		update_score(&Player_one_score);
		printf("\tScore: %d/%d\n", Player_one_score, ++total);
	}
	free(replaced);
	medium_mode();
}

/**
 * hard_mode - Function for difficult gameplay
 *
 */

void hard_mode()
{
	int i;
	char word[7];
	char *replaced = NULL;
	char user[4];
	char *omitted;
	int mistake = 0;
	int j = 0;
	srand(time(NULL));
	strcpy(word, &six_word[rand() % 50][0]);
	omitted = omit_letter(word);
	printf("\n\t⚠ Only input missing letters in the order they should appear\n\tℹ enter 0 to quit\n");
	printf("\n\tComplete: %s\n", omitted);
	printf("\tAnswer: ");
	scanf("%s", user);
	getchar();
	if (user[0] == '0')
	{
		printf("\t\tYou scored: %d/%d\n", Player_one_score, total);
		single_player(mode_select());
		return;
	}
	replaced = replace_word(omitted, user);
	if (!replaced)
	{
		free(replaced);
		exit(EXIT_FAILURE);
	}
	for (i = 0; replaced[i] != '\0'; i++)
	{
		if (replaced[i] != word[i] && replaced[i] & word[i])
		{
			printf("\tWrong\n");
			printf("\n\tScore: %d/%d\n", Player_one_score, ++total);
			mistake++;
			break;
		}
	}
	if (mistake == 0)
	{
		printf("\tCorrect\n");
		update_score(&Player_one_score);
		printf("\n\tScore: %d/%d\n", Player_one_score, ++total);
	}
	free(replaced);
	hard_mode();
}

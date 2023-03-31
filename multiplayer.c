#include "main.h"
/**
 * mode_select - select difficulty
 *
 * @Return: int
 */
int mode_select()
{
	int difficulty;
	printf("\n\t\t**********DIFFICULTY**********\n");
	printf("\n\t\t1. Easy\n\t\t2. Medium\n\t\t3. Hard\n");
	printf("\n\tSelect Difficulty: ");
	scanf("%d", &difficulty);
	return (difficulty);
}

extern char five_word[][6];
extern char four_word[][5];
extern char six_word[][7];
int score = 0;
int total = 0;
void update_score(int *score);
void easy_mode();
/**
 * single_player - single player mode
 *
 */

void single_player(int mode)
{
	if (mode == 0)
		Home();
	else if (mode == 1)
		easy_mode();
}

void multiplayer()
{
}

void update_score(int *score)
{
	printf("\tScore: %d/%d\n", *score += 1, total);
}

void easy_mode()
{
	int i;
	char word[5];
	char replaced[5];
	char user[3];
	char *omitted;
	int mistake = 0;
	int j = 0;
	srand(time(NULL));
	strcpy(word, &four_word[rand() % 50][0]);
	omitted = omit_letter(word);
	printf("\n\t⚠ Only input missing letters in the order they should appear\n");
	printf("\n\tComplete: %s\n", omitted);
	printf("\tAnswer: ");
	scanf("%s", user);
	getchar();
	if (user[0] == '0')
		mode_select();
	for (i = 0; omitted[i] != '\0'; i++)
	{
		if (omitted[i] == '_')
		{
			replaced[i] = user[j];
			j++;
		}
		else
			replaced[i] = omitted[i];
	}
	for (i = 0; replaced[i] != '\0'; i++)
	{
		if (replaced[i] != word[i])
		{
			printf("Wrong\n");
			mistake++;
			break;
		}
	}
	total += 1;
	if (mistake == 0)
		update_score(&score);
	printf("%s\n", word);
	printf("%s\n", replaced);
	easy_mode();
}
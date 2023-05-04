#include "main.h"

char *omit_letter(char *str)
{
	char *str_copy = malloc(sizeof(char) * (strlen(str) + 1));
	int i = 0;
	int half = strlen(str)/2;
	srand(time(NULL));

	while (str[i] != 0)
	{
		str_copy[i] = str[i];
		i++;
	}

	if (strlen(str) == 4)
	{
		str_copy[rand() % 4] = '_';
	}
	else
	{
		for (i = 0; i < half; i++)
		str_copy[rand() % strlen(str)] = '_';
	}
	return (str_copy);
}
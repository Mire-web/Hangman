#include "main.h"


char *omit_letter(char *str)
{
	char *str_copy = malloc(sizeof(char) * (strlen(str) + 1));
	srand(time(NULL));
	int i = 0;
	while (str[i] != 0)
	{
		str_copy[i] = str[i];
		i++;
	}
	if (strlen(str) == 6)
	{
		str_copy[rand()%6] = '_';
		str_copy[rand()%6] = '_';
		str_copy[rand()%6] = '_';
	}
	else if (strlen(str) == 5)
	{
		str_copy[rand()%5] = '_';
		str_copy[rand()%5] = '_';
	}
	else if (strlen(str) == 4)
	{
		str_copy[rand()%4] = '_';
	}
	return(str_copy);
}
#include "shell.h"
/**
 * comment- function that handle the comment lines
 * @str: the line inserted by the user
 * Return: no return
*/
void comment(char *str)
{
	size_t i;

	for (i = 0; i < strlen(str); i++)
	{
		if (str[0] == '#')
		{
			str[0] = '\0';
			break;
		}
		if ((str[i] == '#' && str[i + 1] != '!') && str[i - 1] == ' ')
		{
			str[i] = '\0';
			continue;
		}
	}
}

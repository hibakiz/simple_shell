#include "shell.h"
/**
 * print - our print function
 * @message : pointer char thaat contains the chars to be printed.
 * Return: no rturn
**/

void print(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}

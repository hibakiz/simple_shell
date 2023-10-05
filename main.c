#include "shell.h"
/**
 * main - main function
 *
 * Return: 0
**/

int main(void)
{
	char *buffer;
	size_t n;

	while (1)
	{
		print("$");
		getline(&buffer, &n, stdin);
	}
	return (0);
}

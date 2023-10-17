#include "shell.h"
/**
 * read_line - function that read userinput
 * Return: string ontaining the readed line
 */
char *read_line(void)
{
	 char *line = NULL;
	 size_t len = 0;
	 ssize_t n;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	n = getline(&line, &len, stdin);

	/*handle ctrl+d*/
	if (n == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}

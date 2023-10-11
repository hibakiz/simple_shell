#include "shell.h"
/**
 * read_line - function that read userinput
 * Return: void return
 */
char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t n;
	if (isatty(STDOUT_FILENO))
	{
		write(STDOUT_FILENO,"$ ",1);
		n = getline(&line, &len, stdin);
	}
	else
	{
		free(line);
		return(NULL);
	}
    /*handle ctrl+d*/
	if (n == -1)
	{
		free(line);
		return(NULL);
	}

	return (line);

}
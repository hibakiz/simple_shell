#include "shell.h"
/**
 * read_line - function that read userinput
 * Return: void return
 */
char *read_line(void)
{
<<<<<<< HEAD
	 char *line = NULL;
	 size_t len = 0;
	 ssize_t n;

if (isatty(STDOUT_FILENO))
write(STDOUT_FILENO,"$ ", 2);
	 n = getline(&line, &len, stdin);

	 /*handle ctrl+d*/
if (n == -1)
{
free(line);
return (NULL);
}

return (line);

=======
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

>>>>>>> 6efc5ad3f646eb8f751ecb3db7208a301df6f54a
}

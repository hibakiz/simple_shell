#include "shell.h"
/**
 * main - Entrypoint of sshell program
 * @ac: Count the number of arrguments
 * @argv: Array of strings contatin arguments
 * Return: 0 on success
*/

int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status_cmd = 0, i = 0;
	(void) ac;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDOUT_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(command);
			return (status_cmd);
		}
		command = toknizer(line);
		if (!command)
			continue;
		status_cmd = command_handle(command, argv);

		for (i = 0; command[i] != NULL; i++)
			free(command[i]), command[i] = NULL;

	}
	return (0);
}

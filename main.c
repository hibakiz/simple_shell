#include "shell.h"
/**
 * main - Entrypoint of sshell program
 * @argc: Count the number of arrguments
 * @argv: Array of strings contatin arguments
 * Return: 0 on success
*/

int main(int argc, char **argv)
{
<<<<<<< HEAD
char *line = NULL;
char **command = NULL;
int status_cmd = 0, /*i = 0,*/ index = 0;
(void) ac;
while (1)
{
line = read_line();
if (line == NULL)
{
if (isatty(STDOUT_FILENO))
write(STDOUT_FILENO, "\n", 0);
return (status_cmd);
}
/*i++;*/
index++;
command = toknizer(line);
if (!command)
continue;
status_cmd = command_handle(command, argv, index);
}
=======
	char *line = NULL;
	char **command = NULL;
	int status_cmd = 0, i = 0;
	(void) argc;

	while (1)
	{
		line = read_line();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status_cmd);
		}
		command = toknizer(line);
		if (!command)
			continue;
		status_cmd = command_handle(command, argv);

		free(line);
		for (i = 0; command[i] != NULL; i++)
			free(command[i]), command[i] = NULL;
		free(command), command = NULL;

	}
	return (0);
>>>>>>> 6efc5ad3f646eb8f751ecb3db7208a301df6f54a
}

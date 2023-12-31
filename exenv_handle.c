#include "shell.h"

/**
 * exenv - function to handle the exit and env commands
 * @args: the command
 * @status_cmd: the status to be returned
 * @command: the full command
 * Return: no return
 */
void exenv(char **args, int *status_cmd, char *command)
{
	int i;

	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1])
			*status_cmd = atoi(args[1]);
		free(command);
		free(args);
		exit(*status_cmd);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		free(command);
		free(args);
		exit(*status_cmd);
	}
}

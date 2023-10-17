#include "shell.h"
/**
 * main - Entrypoint of sshell program
 * @argc: Count the number of arrguments
 * @argv: Array of strings contatin arguments
 * Return: 0 on success
*/

int main(int argc, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status_cmd = 0, index = 0;
	(void) argc;

	while (1)
	{
	/*Read the line*/
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status_cmd);
		}

		index++;
		comment(line);/*check if there is a comment*/
	/*Tokenization*/
		command = toknizer(line);
		if (!command)
		continue;
	/*Handle exit and env*/
		if (strcmp(command[0], "exit") == 0 || strcmp(command[0], "env") == 0)
			exenv(command, &status_cmd, command[0]);
	/*Handle other commands*/
		else
		status_cmd = command_handle(command, argv, index);
	}
	return (0);
}

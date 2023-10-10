#include "shell.h"

/**
 * command_handle - Function to handle command execution
 *@command: pointer to command to be execute
 * @argv: pointer to the arugument list for command
 * This function use frok()to create
 * child process that run the program
 * while parent wait
 * Return: Successful execution, returns status of the command
 *execution in the parent process
 *No return in the child process
 */
int command_handle(char **command, char **argv)
{
	pid_t pid;
	int status_cmd = 0, i;

	if (access(command[0], X_OK) == -1)
	{
		for (i = 0; command[i] != NULL; i++)
			free(command[i]), command[i] = NULL;
		free(command), command = NULL;

		perror(argv[0]);
		status_cmd = 127;
		return (status_cmd);
	}
	/*if (!(execve(command[0], command, environ) == -1))*/
		pid = fork();
	(void) **argv;

	if (pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			for (i = 0; command[i] != NULL; i++)
				free(command[i]), command[i] = NULL;
			free(command), command = NULL;
			perror(argv[0]);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status_cmd, 0);
		for (i = 0; command[i] != NULL; i++)
			free(command[i]), command[i] = NULL;
		free(command), command = NULL;
	}
	return (WEXITSTATUS(status_cmd));
}

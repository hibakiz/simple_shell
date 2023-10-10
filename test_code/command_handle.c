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
	int status_cmd = 0;
	pid = fork();
	(void) **argv;

	if (pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			free(command);
			perror(argv[0]);
			exit(0);
		}
	}
	else
	{
		waitpid(pid, &status_cmd, 0);
	}
	return (WEXITSTATUS(status_cmd));
}

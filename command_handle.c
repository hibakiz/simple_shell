#include "shell.h"

/**
 * command_handle - Function to handle command execution
 *@command: pointer to command to be execute
 * @argv: pointer to the arugument list for command
 * @index: the index of the command
 * This function use frok()to create
 * child process that run the program
 * while parent wait
 * Return: Successful execution, returns status of the command
 *execution in the parent process
 *No return in the child process
 */
int command_handle(char **command, char **argv, int index)
{
	char *full_path;
	pid_t pid;
	int status_cmd = 0;

	/*Get the full path*/
	full_path = _getpath(command[0]);
	if (!full_path)
	{
		printerror(argv[0], command[0], index);
		free_pointer(command);
		return (127);
	}
	/*Create a child process*/
	pid = fork();
	if (pid == 0) /*The child process*/
	{
		if (execve(full_path, command, environ) == -1)
		{
			free(full_path), full_path = NULL;
			free_pointer(command);

		}
	}
	else if (pid > 0) /*Parent process*/
		waitpid(pid, &status_cmd, 0);
	/*Finish*/
	free_pointer(command);
	free(full_path), full_path = NULL;
	return (WEXITSTATUS(status_cmd));
}

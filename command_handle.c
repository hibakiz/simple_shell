#include "shell.h"
void command_handle (char **command)
{
	char *path = "/bin/", *cmd;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		cmd = malloc(strlen(path) + strlen(command[0]) + 1);
		strcpy(cmd, path);
		strcat (cmd, command[0]);
		execve(cmd, command, NULL);}
	else if (pid > 0)
		wait(NULL);
	else
		return;
}

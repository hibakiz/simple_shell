#include "shell.h"
int command_handle (char **command, char **argv)
{
/*	char *path = "/bin/", *cmd;*/
	pid_t pid;
	int status_cmd;

	pid = fork();
	if (pid == 0)
	{
/*		cmd = malloc(strlen(path) + strlen(command[0]) + 1);
		strcpy(cmd, path);
		strcat (cmd, command[0]);
	 (execve(cmd, command, NULL)
	*/
	if (execve(command[0], command, environ) == -1)	
	 {
perror(argv[0]);
free(command);		
exit(0);
     
	 }
	}
	else
	{
		waitpid(pid, &status_cmd, 0);
free(command);
	}
return(WEXITSTATUS(status_cmd));
	}
	

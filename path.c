#include "shell.h"

char *_getpath(char *user_command)
{
	char *current_path = getenv("PATH");
	char *token, *dupl;
	char buff[256];
	char *path = NULL;

	if (strchr(user_command, '/') != NULL)
	{
		path = strdup(user_command);
		return (path);
	}
	if (current_path == NULL)
		return (NULL);
	
	dupl = strdup(current_path);
	token = strtok(dupl, ":");

	while(token)
	{
		strcpy(buff,token);
		strcat(buff, "/");
		strcat(buff, user_command);
		if (access(buff, X_OK) == 0)
		{
			path = strdup(buff);
			free(dupl);
			return (path);
		}
		
		token = strtok(NULL, ":");
	}
	free(token);
	free(dupl);
	return (NULL);
}



/*int main()
{
	char *command = "ls";
	char *fullpath = get_path(command);
	free(fullpath);
	
	return(0);
}
int main()
{
	char *current_path = getenv("PATH");
	printf("%s\n", current_path);

	return (0);
}*/

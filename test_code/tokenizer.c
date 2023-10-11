#include "shell.h"
char **toknizer(char *line)
{
	char *token = NULL;
	char *tmp = NULL;
	char **commands = NULL;
	int cpt = 0, i =0;

	tmp = strdup(line);
/*	free(line), line = NULL;*/
	token = strtok(tmp, " \t\n");
	if (token == NULL)
	{
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		cpt++;
		token = strtok(NULL, " \t\n");
	}
	free(tmp), tmp = NULL;
	commands = malloc(sizeof(char *) * (cpt + 1));
	if (commands == NULL)
	{
		return (NULL);
	}
	token = strtok(line, " \t\n");
	while (token)
	{
		commands[i] = strdup(token);
		token = strtok(NULL, " \t\n");    
		i++;
	}
	/*
	command[i] = NULL;*/
	free(token), token = NULL;
	return (commands);
}

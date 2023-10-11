#include "shell.h"
/**
 * toknizer - Entrypoint of sshell program
 * @line: string of the the inserted line
 * Return: array of strings
*/
char **toknizer(char *line)
{
	char *token = NULL;
	char *tmp = NULL;
	char **commands = NULL;
	int cpt = 0, i = 0;

	if (!line)
		return (NULL);

	tmp = strdup(line);
	token = strtok(tmp, del);

	if (token == NULL)
	{
		free(tmp), tmp = NULL;
		free(line), line = NULL;
		return (NULL);
	}
	while (token)
	{
		cpt++;
		token = strtok(NULL, del);
	}
	free(tmp), tmp = NULL;
	commands = malloc(sizeof(char *) * (cpt + 1));
	if (commands == NULL)
	{
		free(line);
		return (NULL);
	}
	token = strtok(line, del);
	while (token)
	{
		commands[i] = strdup(token);
		token = strtok(NULL, del);
		i++;
	}

	free(line), line = NULL;
	commands[i] = NULL;
	return (commands);
}

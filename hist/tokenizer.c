#include "shell.h"
/**
 * toknizer - function that spilit string to token
 * @line: string to be spilted
 * Return: array of pointer to token strings
*/
char **toknizer(char *line)
{
	char *token = NULL;
	char *tmp = NULL;

	char **command = NULL;
	int cpt = 0, i = 0;

	if (!line)
	return (NULL);
	tmp = _strdup(line);
	token = strtok(tmp, " \t\n");
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		cpt++;
		token = strtok(NULL, " \t\n");
	}
free(tmp), tmp = NULL;
command = malloc(sizeof(char *) * (cpt + 1));
if (!command)
{
	free(line);
	return (NULL);
}
token = strtok(line, " \t\n");

while (token)
{
command[i] = _strdup(token);
token = strtok(NULL, " \t\n");
i++;
}
free(line), line = NULL;
command[i] = NULL;
return (command);

}

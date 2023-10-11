#include "shell.h"
/**
<<<<<<< HEAD
 * toknizer - function that spilit string to token
 * @line: string to be spilted
 * Return: array of pointer to token strings
=======
 * toknizer - Entrypoint of sshell program
 * @line: string of the the inserted line
 * Return: array of strings
>>>>>>> 6efc5ad3f646eb8f751ecb3db7208a301df6f54a
*/
char **toknizer(char *line)
{
	char *token = NULL;
	char *tmp = NULL;
<<<<<<< HEAD

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
=======
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
>>>>>>> 6efc5ad3f646eb8f751ecb3db7208a301df6f54a
		return (NULL);
	}
	while (token)
	{
		cpt++;
<<<<<<< HEAD
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
=======
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
>>>>>>> 6efc5ad3f646eb8f751ecb3db7208a301df6f54a

	free(line), line = NULL;
	commands[i] = NULL;
	return (commands);
}

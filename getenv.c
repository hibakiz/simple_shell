# include "shell.h"
/**
 * _getenv - Get the value of an environment variable.
 * @variable: The name of the environment variable.
 *
 * Return: The value of the environment variable , otherwise NULL.
 */
char *_getenv(char *variable)
{
	int i;
	char  *env, *name, *value, *copy;

	for (i = 0; environ[i] != NULL; i++)
	{
		copy = _strdup(environ[i]);
		name = strtok(copy, "=");
		if (_strcmp(name, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(copy);
			return (env);
		}
		free(copy), copy = NULL;
	}
	free(copy);
	free(name);
	free(variable);
	return (NULL);
}

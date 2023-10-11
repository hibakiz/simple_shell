#include "shell.h"
/**
 * getpath - function that return full path
 * @command: input command
 * Return: full path of input command
*/
char *_getpath(char *command) 
{
    int i;
char *path, *full_path, *toke;
struct stat s;
path = _getenv("PATH");
if(!path)
return(NULL);
toke = strtok(path, ":");
for (i = 0; command[i]; i++)
{
    if (command[i] == '/')
    {
        if (stat(command, &s) == 0)
        return(_strdup(command));
        return(NULL);
    }
}

while (toke)
{
    full_path = malloc(_strlen(toke) + _strlen(command) + 2);
if (full_path)
{
    _strcpy(full_path, toke);
    _strcat(full_path, "/");
    _strcat(full_path, command);
    if(stat(full_path, &s) == 0)
    {
        free(path);
        return(full_path);
    }
    free(full_path), full_path = NULL;
    toke = strtok(NULL, ":");
}
}
free(path);
return(NULL);
}

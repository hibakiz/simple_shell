#include "shell.h"
/**
 * getpath - function that return full path
 * @command: input command
 * Return: full path of input command
*/
char *_getpath(char *command) 
{
    char *path, *path_copy, *toke, *full_path;
int i;
    struct stat s;
path = _getenv("PATH");
if (path == NULL || _strlen(path) == 0)
return (NULL);
for (i = 0; command[i]; i++)
{
    if (command[i] == '/')
    {
        if (stat(command, &s) == 0)
        return(_strdup(command));
        return(NULL);
    }
}
if(!path)
return(NULL);
else
  if (path){
    path_copy = strdup(path);
        toke = strtok(path_copy, ":");
        while(toke != NULL){
              full_path = malloc(strlen(toke)+ strlen(command) + 2); 
            strcpy(full_path, toke);
            strcat(full_path, "/");
            strcat(full_path, command);
            strcat(full_path, "\0");
            if (stat(full_path, &s) == 0){
                free(path_copy);
                return (full_path);
            }
            else{
                free(full_path), full_path = NULL;
                toke = strtok(NULL, ":");
            }
        }
  free(path_copy);
        if (stat(command, &s) == 0)
        {
            return (command);
        }
        return (NULL);
    }
    return (NULL);
}

/*int main (int argc, char **av)
{
    char * full_path;
    full_path = _getpath(av[1]);
    if (full_path)
    printf("%s\n", full_path);
    else 
    printf("dose not exit\n");
   
}
*/
/*
gcc  path.c strings.c getenv.c  -o a
*/

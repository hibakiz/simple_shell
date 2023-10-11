#include "shell.h"
/**
 * printerror - function disply error message
 * @name: the name of function
 * @cmd: command cuase error
 * @index: location of error
 * Return: no return
*/
void printerror(char *name, char *cmd, int index)
{
    char *i, msg[] = ": No such file or directory \n";
    i = _itoa(index);
    write(STDERR_FILENO, name, _strlen(name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, i, _strlen(i));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, _strlen(cmd));
    write(STDERR_FILENO, msg, _strlen(msg));
    free(i);



}

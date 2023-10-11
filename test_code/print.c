#include "shell.h"
#include <unistd.h>

/**
 * Print - Our print function
 *
 * @message: The string to be printed.
 * @Return: no return
 */
void print(char *message){
    write(STDOUT_FILENO, message, strlen(message));
    free(message);
}

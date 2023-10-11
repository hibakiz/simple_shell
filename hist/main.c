#include "shell.h"
/**
 * main - Entrypoint of sshell program
 * @ac: Count the number of arrguments
 * @argv: Array of strings contatin arguments
 * Return: 0 on success
*/

int main(int ac, char **argv)
{
char *line = NULL;
char **command = NULL;
int status_cmd = 0, /*i = 0,*/ index = 0;
(void) ac;
while (1)
{
line = read_line();
if (line == NULL)
{
if (isatty(STDOUT_FILENO))
write(STDOUT_FILENO, "\n", 0);
return (status_cmd);
}
/*i++;*/
index++;
command = toknizer(line);
if (!command)
continue;
status_cmd = command_handle(command, argv, index);
}
}

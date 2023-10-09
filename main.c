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
int status_cmd = 0;
(void) ac;
int i;
while (1)
{
line = read_line();
if (line == NULL)
{
if (isatty(STDOUT_FILENO))
write(STDOUT_FILENO, "\n", 1);
return (status_cmd);
}
command = toknizer(line);
if (!command)
return;
for (i = 0; command[i]; i++)
{
free(command[i]), command[i] = NULL;
}
free(command), command = NULL;
status_cmd = command_handle(command, argv);
}
}

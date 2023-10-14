#include "shell.h"
/**
 * main - Entrypoint of sshell program
 * @ac: Count the number of arrguments
 * @argv: Array of strings contatin arguments
 * Return: 0 on success
*/

int main(int argc, char **argv)
{
char *line = NULL;
char **command = NULL;
int status_cmd = 0, index = 0;
(void) argc;
while (1)
{
line = read_line();
if (line == NULL)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
return (status_cmd);
}

/*i++;*/
index++;
command = toknizer(line);
if (!command)
continue;
if (strcmp(command[0], "exit") == 0 || strcmp(command[0], "env") == 0)
			exenv(command, &status_cmd, command[0]);
else
status_cmd = command_handle(command, argv, index);

}
return (0);
}

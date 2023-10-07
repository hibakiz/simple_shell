#include "shell.h"
/**
 * main - Entrypoint of sshell program
 * @ac: Count the number of arrguments
 * @av: Array of strings contatin arguments
 * Return: 0 on success
*/

int main(int ac, char **argv)
{
    char *line = NULL;
  char **command = NULL;
/*    int i = 0;*/
    int status_cmd = 0;
    (void) ac;
    
    while (1)
    {
        line = read_line();
       if (line == NULL)
       {
	 if (isatty(STDOUT_FILENO))
		write(STDOUT_FILENO, "\n",1);
	       return (status_cmd);
       }

        command = toknizer(line);
/*        command_handle(command);*/
        if (!command)
        continue;
/*        for (i = 0; command[i]; i++)
        printf("%s\n", command[i]); 
	
	*/
	status_cmd = command_handle(command, argv);
    }
}

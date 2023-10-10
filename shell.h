#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>



void prompt(void);
extern char **environ;
#define del " \t\n"
char *_strdup(char *str);
/*void print(char *message);*/
char **toknizer(char *line);
char *read_line(void);
int command_handle(char **command, char **argv);

#endif

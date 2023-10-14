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

/*void prompt(void);*/
#define del " \t\n"
char *remove_spaces(char *str);
char *_getenv(char *variable);
extern char **environ;
int _strcmp(char *c1, char *c2);

int _strlen(char *c);
char *_strcat(char *x1, char *x2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_getpath(char *command) ;
char **toknizer(char *line);
char *read_line(void);
/*void command_handle (char **command);*/
int command_handle(char **command, char **argv, int index);
void free_pointer(char **ptr);
void reverse_string(char *str, int len);
char *_itoa(int x);
void printerror(char *name, char *cmd, int index);
void exenv(char **args, int *status, char *command);
#endif

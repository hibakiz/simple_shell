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

<<<<<<< HEAD
/*void prompt(void);*/
char *_getenv(char *variable);
extern char **environ;
int _strcmp(char *c1, char *c2);
int _strlen(char *c);
char *_strcat(char *x1, char *x2);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
char *_getpath(char *command) ;
char **toknizer(char *line);
char *read_line(void);
/*void command_handle (char **command);*/
int command_handle(char **command, char **argv, int index);
void free_pointer(char **ptr);
void reverse_string(char *str, int len);
char *_itoa(int x);
void printerror(char *name, char *cmd, int index);
=======


void prompt(void);
extern char **environ;
#define del " \t\n"
char *_strdup(char *str);
/*void print(char *message);*/
char **toknizer(char *line);
char *read_line(void);
int command_handle(char **command, char **argv);

>>>>>>> 6efc5ad3f646eb8f751ecb3db7208a301df6f54a
#endif

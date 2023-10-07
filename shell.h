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

char *_strdup(const char *str);
void print(const char *message);
char **toknizer(char *line);
char *read_line(void);
void command_handle (char **command);

#endif

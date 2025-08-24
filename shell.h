#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char *read_line(void);
int is_exit(char *line);
char **split_string(char *str);
char *find_in_path(char *command);
void execute_command(char **argv);

#endif


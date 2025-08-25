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
char *find_in_path(char *command, char **envp);
void execute_command(char **argv, char **envp);
char *get_path_env(char **envp);
char *search_command_in_path(char *path, char *command);
#endif


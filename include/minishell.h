#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 64

char *read_input(void);
char **parse_input(char *line);
void execute_command(char *line);

int is_builtin(char *cmd);
int exec_builtin(char **args);


#endif


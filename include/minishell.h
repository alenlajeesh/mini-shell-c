#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_ARGS 64

/* input */
char *read_input(void);

/* parser */
char **parse_input(char *line);
void strip_quotes(char **args);

/* execution */
void execute_command(char *line);

/* builtins */
int is_builtin(char *cmd);
int exec_builtin(char **args);

/* redirection */
int handle_redirection(char **args);

/* signals */
void sigint_handler(int sig);

#endif



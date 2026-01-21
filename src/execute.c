#include "minishell.h"

void execute_command(char *line)
{
    char **args = parse_input(line);
	strip_quotes(args);
    if (!args[0])
    {
        free(args);
        return;
    }

    if (is_builtin(args[0]))
    {
        exec_builtin(args);
        free(args);
        return;
    }

    pid_t pid = fork();
    if (pid == 0)
    {
        handle_redirection(args);
        execvp(args[0], args);
        perror("exec");
        exit(1);
    }
    else if (pid > 0)
    {
        wait(NULL);
    }
    else
    {
        perror("fork");
    }

    free(args);
}


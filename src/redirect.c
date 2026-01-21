#include "minishell.h"

int handle_redirection(char **args)
{
    for (int i = 0; args[i]; i++)
    {
        // Append >>
        if (strcmp(args[i], ">>") == 0)
        {
            if (!args[i + 1])
            {
                fprintf(stderr, "minishell: syntax error\n");
                return -1;
            }

            int fd = open(args[i + 1],
                          O_CREAT | O_WRONLY | O_APPEND,
                          0644);
            if (fd < 0)
            {
                perror("open");
                return -1;
            }

            dup2(fd, STDOUT_FILENO);
            close(fd);

            args[i] = NULL;
            return 1;
        }

        // Overwrite >
        if (strcmp(args[i], ">") == 0)
        {
            if (!args[i + 1])
            {
                fprintf(stderr, "minishell: syntax error\n");
                return -1;
            }

            int fd = open(args[i + 1],
                          O_CREAT | O_WRONLY | O_TRUNC,
                          0644);
            if (fd < 0)
            {
                perror("open");
                return -1;
            }

            dup2(fd, STDOUT_FILENO);
            close(fd);

            args[i] = NULL;
            return 1;
        }

        // Case: >file or >>file (no space)
        if (args[i][0] == '>' && args[i][1] != '\0')
        {
            if (args[i][1] == '>')
            {
                int fd = open(args[i] + 2,
                              O_CREAT | O_WRONLY | O_APPEND,
                              0644);
                if (fd < 0) { perror("open"); return -1; }

                dup2(fd, STDOUT_FILENO);
                close(fd);
                args[i] = NULL;
                return 1;
            }
            else
            {
                int fd = open(args[i] + 1,
                              O_CREAT | O_WRONLY | O_TRUNC,
                              0644);
                if (fd < 0) { perror("open"); return -1; }

                dup2(fd, STDOUT_FILENO);
                close(fd);
                args[i] = NULL;
                return 1;
            }
        }
    }

    return 0;
}


#include "minishell.h"

char *read_input(void)
{
    char *line = NULL;
    size_t len = 0;

    printf("minishell$ ");
    fflush(stdout);

    if (getline(&line, &len, stdin) == -1)
    {
        if (errno == EINTR)
        {
            free(line);
            return strdup("");
        }
        free(line);
        return NULL;
    }

    // Ctrl+L (form feed)
    if (line[0] == '\f')
    {
        system("clear");
        free(line);
        return strdup("");
    }

    return line;
}


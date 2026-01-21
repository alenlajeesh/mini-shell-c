#include "minishell.h"

void sigint_handler(int sig)
{
    (void)sig;
    write(1, "\n", 1);
}


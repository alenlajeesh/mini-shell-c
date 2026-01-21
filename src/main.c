#include "minishell.h"

static void setup_signals(void)
{
    struct sigaction sa;

    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;   // IMPORTANT

    sigaction(SIGINT, &sa, NULL);
    signal(SIGQUIT, SIG_IGN);
}

int main(void)
{
    char *line;

    setup_signals();

    while (1)
    {
        line = read_input();
        if (!line)
            break;

        execute_command(line);
        free(line);
    }
    return 0;
}


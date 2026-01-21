#include "minishell.h"

char **parse_input(char *line)
{
    char **args = malloc(sizeof(char *) * MAX_ARGS);
    int i = 0;

    while (*line)
    {
        while (*line == ' ' || *line == '\t' || *line == '\n')
            line++;

        if (*line == '\0')
            break;

        if (*line == '"')  // start of quoted string
        {
            line++; // skip opening quote
            args[i++] = line;
            while (*line && *line != '"')
                line++;
            if (*line) *line++ = '\0'; // terminate quoted string
        }
        else
        {
            args[i++] = line;
            while (*line && *line != ' ' && *line != '\t' && *line != '\n')
                line++;
            if (*line) *line++ = '\0';
        }
    }

    args[i] = NULL;
    return args;
}
void strip_quotes(char **args)
{
    for (int i = 0; args[i]; i++)
    {
        char *s = args[i];
        size_t len = strlen(s);
        if (len >= 2 && s[0] == '"' && s[len-1] == '"')
        {
            memmove(s, s+1, len-2);
            s[len-2] = '\0';
        }
    }
}



#include "minishell.h"

char **parse_input(char *line){
	
	char **args =malloc(sizeof(char *)* MAX_ARGS);
	char *token;
	int i=0;

	token =strtok(line," \t\n");

	while(token && i< MAX_ARGS -1){
		args[i++] =token;
		token=strtok(NULL," \t\n");
	}

	args[i]=NULL;
	return args;

}

char **split_pipe(char *line, int *count)
{
    char **cmds = malloc(sizeof(char *) * MAX_ARGS);
    char *token;
    int i = 0;

    token = strtok(line, "|");
    while(token && i < MAX_ARGS - 1)
    {
        while(*token == ' ') token++; // trim leading spaces
        cmds[i++] = token;
        token = strtok(NULL, "|");
    }
    cmds[i] = NULL;
    *count = i;
    return cmds;
}

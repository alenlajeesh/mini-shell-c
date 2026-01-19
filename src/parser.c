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

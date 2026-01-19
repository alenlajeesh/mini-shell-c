#include "minishell.h"

char *read_input(void){
	char *line =NULL;
	size_t len =0;
	printf("minishell$ ");

	if(getline(&line,&len,stdin)==-1){
		free(line);
		return NULL;
	}
	return line;
}

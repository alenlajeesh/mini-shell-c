#include "minishell.h"

int main(void){
	char *line;
	
	while(1){
		line=read_input();

		if(!line){
			break;
		}

		execute_command(line);
		free(line);
	}
	return 0;
}

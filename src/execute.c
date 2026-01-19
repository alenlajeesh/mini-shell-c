#include "minishell.h"

void execute_command(char *line){

	char **args =parse_input(line);
	pid_t pid;

	if(!args[0]){
		free(args);
		return;
	}
	
	if(is_builtin(args[0])){
		exec_builtin(args);
		free(args);
		return;
	}

	pid=fork();

	if(pid==0){
		execvp(args[0],args);
		perror("exec");
		exit(1);
	}
	else{
		wait(NULL);
	}

	free(args);
}

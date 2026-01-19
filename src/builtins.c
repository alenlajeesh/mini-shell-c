#include "minishell.h"

int is_builtin(char *cmd){
	return (strcmp(cmd, "cd")==0 || strcmp(cmd,"exit")==0);
}

int exec_builtin(char **args){
	if(strcmp(args[0],"cd")==0){
		if(!args[1]){
			return chdir(getenv("HOME"));
		}
		return chdir(args[1]);
	}

	if(strcmp(args[0],"exit")==0){
		exit(0);
	}

	return -1;
	
}



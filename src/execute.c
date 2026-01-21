#include "minishell.h"

void execute_command(char *line){
	
	if(strchr(line, '|'))
    {
        execute_pipes(line);
        return;
    }
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

#include "minishell.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

void execute_pipes(char *line)
{
    int num_cmds;
    char **cmds = split_pipe(line, &num_cmds);
    int i;
    int fd[2], in_fd = 0; // in_fd for previous pipe read end

    for(i = 0; i < num_cmds; i++)
    {
        pipe(fd); // create pipe for this command

        pid_t pid = fork();
        if(pid == 0)
        {
            // Child

            // If not first command, redirect stdin
            if(in_fd != 0)
                dup2(in_fd, STDIN_FILENO);

            // If not last command, redirect stdout
            if(i != num_cmds - 1)
            {
                dup2(fd[1], STDOUT_FILENO);
            }

            // Close unused fds
            close(fd[0]);
            if(in_fd != 0) close(in_fd);
            close(fd[1]);

            // Parse this command into args
            char **args = parse_input(cmds[i]);

            // Check built-ins only if single command
            if(num_cmds == 1 && is_builtin(args[0]))
            {
                exec_builtin(args);
                free(args);
                exit(0);
            }

            execvp(args[0], args);
            perror("exec");
            exit(1);
        }
        else
        {
            // Parent
            wait(NULL);
            close(fd[1]);       // close write end in parent
            if(in_fd != 0) close(in_fd); // close previous read end
            in_fd = fd[0];      // save read end for next command
        }
    }

    free(cmds);
}


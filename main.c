#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - main
 *
 * Return: 0 on success
*/
int main(void)
{
	char *prompt = retrieve_prompt();
	char command[128];
	char *argv[2];
	char *envv[1] = {NULL};
	int status;
	pid_t pid;

	while (1)
	{
		printf("%s ", prompt);
		scanf("%s", command);

		argv[0] = command;
		argv[1] = NULL;

		pid = fork();
		waitpid(pid, &status, 0);

		if (pid == 0)
		{
			if (execve(command, argv, envv) == -1)
				perror("Error");
		}
	}

	return (0);
}

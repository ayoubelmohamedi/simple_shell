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
int main(int argc, char **argv)
{
	char *prompt = retrieve_prompt();
	char command[128];
	char *av[2];
	char *ev[1] = {NULL};
	int status;
	pid_t pid;

	(void)argc;

	while (1)
	{
		printf("%s ", prompt);
		scanf("%s", command);

		av[0] = command;
		av[1] = NULL;

		pid = fork();
		waitpid(pid, &status, 0);

		if (pid == 0)
		{
			if (execve(command, av, ev) == -1)
				perror(argv[0]);
		}
	}

	return (0);
}

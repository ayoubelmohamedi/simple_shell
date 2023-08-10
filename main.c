#include "main.h"
#include <stdio.h>

/**
 * main - main
 *
 * Return: 0 on success
*/
int main(int argc, char **argv)
{
	char *prompt = retrieve_prompt();
	char command[128];
	char *cfile = argv[0];

	(void)argc;

	while (1)
	{
		printf("%s ", prompt);
		scanf("%s", command);

		fork_process(command, cfile);
	}
	return (0);
}

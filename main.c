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
	char **cfile = 	argv;
	char *cmd;
	
	cmd = argv[0];
	(void)argc;

	while (1)
	{
		printf("%s ", prompt);

		if (scanf("%99[^\n]%*c", cmd) != 1)
		{
			while (getchar() != '\n');
			continue;
		}
		fork_process(cmd, cfile);
	}
	return (0);
}

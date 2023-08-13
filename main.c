#include "main.h"

/**
 * main - main
 *
 * Return: 0 on success
*/
int main(int argc, char **argv)
{
	char *prompt = retrieve_prompt();
	char *cmd = (char *)malloc(100);

	if (!cmd) {
        perror("Memory allocation failed:");
        return (1);	
    }	

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
		fork_process(cmd, argv);
	}

	free(cmd);
	return (0);
}

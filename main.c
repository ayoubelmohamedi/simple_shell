#include "main.h"

/**
 * main - main
 *
 * Return: 0 on success
*/
int main(int argc, char **argv)
{

	char *prompt = retrieve_prompt();
   	char *input, **cmd;

    	while (1)
    	{
		if (isatty(STDIN_FILENO))
        		printf("%s ", prompt);

        	input = getline();

		if (input[0] == '\0')
		{
			continue;
		}

		cmd = parse_cmd(input);

        	if (argc > 1)
            		fork_process(argv[1], cmd);
    }

    return (0);
}

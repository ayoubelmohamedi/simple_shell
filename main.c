#include "main.h"

/**
 * main - main
 *
 * Return: 0 on success
*/
int main(int argc, char **argv)
{
	char *prompt = retrieve_prompt();
    char input[100];

    while (1)
    {
        printf("%s ", prompt);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            perror("Error");
            continue;
        }

		argc = 1;
        argv[argc] = strtok(input, " \n");
        while (argv[argc] != NULL)
        {
            argc++;
            argv[argc] = strtok(NULL, " \n");
        }

        if (argc > 1)
            fork_process(argv[1], argv);
    }

    return (0);
}

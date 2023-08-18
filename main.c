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
    char *path = _getenv("PATH") ;
    char *__exit__ = "exit";

    while (1)
    {
        printf("%s ", prompt);

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        if (_strcmp(input, __exit__) == 0)
            exit(0);

		argc = 1;
        argv[argc] = strtok(input, " \n");
        while (argv[argc] != NULL)
        {
            argc++;
            argv[argc] = strtok(NULL, " \n");
        }

        if (argc > 1)
        {
            char *full_path = get_path(argv[1], path);
            argv[1] = full_path;

            fork_process(full_path, argv);
        }
    }

    return (0);
}

#include "main.h"

/**
 * main - main
 * @argc: number of args
 * @argv: array of args
 *
 * Return: 0 on success
*/
int main(int argc, char **argv)
{
	/*char *prompt = retrieve_prompt();*/
	int check_terminal = isatty(0);
	size_t input_size = 128;
	char *input = (char *)malloc(input_size);
	char *path = _getenv("PATH");
	int latest_exit_status = 0;

	while (1)
	{
		if (check_terminal == 1)
			write(STDOUT_FILENO, "$ ", 2);

		if (getline(&input, &input_size, stdin) == EOF)
			break;

		if (_strcmp(input, "exit") == 0)
			exit(latest_exit_status);

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
			latest_exit_status = argc - 1;
			fork_process(full_path, argv);
		}
	}
	free(input);

	return (0);
}

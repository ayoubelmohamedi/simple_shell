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
	char *prompt = retrieve_prompt();
	size_t input_size = 128;
	char *input = (char *)malloc(sizeof(input_size));
	char *path = _getenv("PATH");
	char *__exit__ = "exit";

	while (1)
	{
		write(1, prompt, _strlen(prompt));

		if (getline(&input, &input_size, stdin) == EOF)
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
	free(input);

	return (0);
}

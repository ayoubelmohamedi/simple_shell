#include "main.h"

/**
 * parse_cmd - Parse Line Of Input
 * @input:User Input To Parse
 * Return: Array Of Char (Parsed):Simple Shell
 */
char **parse_cmd(char *input)
{
	char **tokens;
	char *token;
	int i, buffsize = BUFSIZE;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = strtok(input, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}

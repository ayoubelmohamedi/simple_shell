#include "main.h"
#include <stdio.h>

/**
 * main - main
 *
 * Return: 0 on success
*/
int main()
{
	char *prompt = retrieve_prompt();
	char user_input[100];

	while(1)
	{
		printf("%s ", prompt);
		scanf("%s", user_input);
	}

	return (0);
}

#include "main.h"

/**
 * retrieve_prompt - makes proper prompt for the user
 *
 * Return: prompt
*/
/*char *retrieve_prompt()
{
	uid_t uid = getuid();

	struct passwd *user_info = getpwuid(uid);

	static char prompt[2048];
	char cwd[1024];

	if (user_info == NULL)
	{
		perror("getpwuid");
		return (NULL);
	}

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		return (NULL);
	}

	_strcpy(prompt, user_info->pw_name);
	_strcat(prompt, ":");
	_strcat(prompt, cwd);
	_strcat(prompt, "$ ");

	return (prompt);
}*/

/**
 * fork_process - Executes a command in a child process.
 * @cmd: commad
 * @args: An array of arguments.
*/
void fork_process(char *cmd, char **args)
{
	pid_t child_pid;
	int status;
	char *ev[] = {NULL};

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		execve(cmd, args + 1, ev);
		perror(args[0]);
		exit(EXIT_FAILURE);

	}
	else
		wait(&status);
}

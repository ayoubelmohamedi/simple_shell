#include "main.h"

void cmd_run(char *cmd, char* cfile);

/**
 * retrieve_prompt - makes proper prompt for the user
 *
 * Return: prompt
*/
char *retrieve_prompt()
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

	strcpy(prompt, user_info->pw_name);
	strcat(prompt, ":");
	strcat(prompt, cwd);
	strcat(prompt, "$");

	return (prompt);
}

/**
 * for_process - Executes a command in a child process.
 * @args:  An array of arguments.
 * @cfile:  A double pointer to the beginning of args.
*/
void fork_process(char **args, char **front)
{
	pid_t child_pid;
	int status, flag = 0;
	char *command = args[0];

	child_pid = fork();
	if (child_pid == -1)
	{
		if (flag)
			free(command);
		perror("Error child:");
		return (1);
	}
	if (child_pid == 0)
	{
		execve(command, args, environ);
		if (errno == EACCES)
			ret = (create_error(args, 126));
	}
	else
		wait(&status);	
		
	if (flag)
		free(command);
	
}

/**
 * cmd_run - executes given file
 * @cmd: command to use
 * @cfile: file's name, AKA argv[0]
*/
void cmd_run(char *cmd, char* cfile)
{
	char *av[2];
	char *ev[1] = {NULL};

	av[0] = cmd;
	av[1] = NULL;

	if (execve(cmd, av, ev) == -1)
		perror(cfile);
}

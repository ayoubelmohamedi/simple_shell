#include "main.h"

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
void fork_process(char *cmd, char **cfile)
{
	pid_t child_pid;
	int status;
	char *ev[] = {NULL};
	
	child_pid = fork();
	if (child_pid == -1) 
	{
       		perror("Error fork:");
        	exit(EXIT_FAILURE);
    	}

	if (child_pid == 0)
	{
		execve(cmd, cfile, ev);
		perror("Error execve:");
        	exit(EXIT_FAILURE);
	
	}
	else
		wait(&status);	
	
}

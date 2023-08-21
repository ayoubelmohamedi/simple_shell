#include "main.h"

/**
 * get_path: Creates full path of binary code and executables
 * @cmd: Initial cmd frag
 * @path: $PATH
 * 
 * Return: full_path or cmd on success
*/
char *get_path(char *cmd, char *path)
{
	char full_path[256];

	if (cmd[0] == '/')
		return (cmd);
    
    if (path != NULL)
	{
		char *path_copy = _strdup(path);
        char *token;

        token = strtok(path_copy, ":");

        while (token != NULL)
		{
            snprintf(full_path, sizeof(full_path), "%s/%s", token, cmd);

            if (access(full_path, F_OK) == 0)
			{
				free(path_copy);
                return _strdup(full_path);
			}

            token = strtok(NULL, ":");
        }
		free(path_copy);
    }
    return (NULL);
}

#ifndef MAIN_H
#define MAIN_H

/**##### MACROS ######*/

#define BUFSIZE 1024

/**###### LIBS USED ######*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/wait.h>


char *retrieve_prompt();
void fork_process(char *cmd, char **args);
#endif

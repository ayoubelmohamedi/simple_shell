#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* SIMPLE_SHELL_C */
/*char *retrieve_prompt();*/
int fork_process(char *cmd, char **args);

/* PATH_HANDLING_C */
char *get_path(char *cmd, char *path);
char *_getenv(const char *env_var);

/* EXIT_C */
int _WIFEXITED(int status);

/* FUNC1_C */
int _strcmp(char *str1, char *str2);
int _strncmp(const char *str1, const char *str2, size_t n);
size_t _strcspn(const char *s, const char *reject);
char *_strdup(char *str);
int _strlen(char *str);

/* FUNC2_C */
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

#endif

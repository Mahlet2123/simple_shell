#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

char *_read_line(void);
char **_parse(char *str, char *delim);

/**path handlers*/
char **copy_envp(char **envp);
char *get_path(char **new_envp, char *path);
char *check_cmd(char **dir, char *tokens);

/**string modifiers*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *str_concat(char *s1, char *s2);

#endif

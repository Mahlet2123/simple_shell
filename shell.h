#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;

struct builtin
{
	char *env;
	char *exit;
} builtin;

/* functions */
void prompt(void);
char *_read_line(void);
char **_parse(char *str, char *delim);
int checker(char **cmd, char *buf);
void execution(char *cp, char **cmd);
int handle_builtin(char **cmd, char *line);
void exit_cmd(char **cmd, char *line);
void print_env(void);

/**path handlers*/
char **copy_envp(void);
char *get_path(char **new_envp, char *path);
char *check_cmd(char **dir, char *tokens);

/**string modifiers*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);

#endif

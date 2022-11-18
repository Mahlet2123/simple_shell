#include "shell.h"

/**
 * handle_builtin - handles execution of builtin functions
 * @cmd: tokenized commands
 * @line: input read from stdin
 *
 * Return: 1 if executed, 0 if not
 */

int handle_builtin(char **cmd, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*cmd, builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_strcmp(*cmd, builtin.exit) == 0)
			{
				exit_cmd(cmd, line);
				return (1);
			}
	return (0);
}

/**
 * exit_cmd - handles the exit command
 * @cmd: tokenized command
 * @line: input read from stdin
 * Return: no return
 */

void exit_cmd(__attribute__((__unused__))char **cmd, char *line)
{
	free(line);
	exit(0);
}

/**
 * print_env - prints the environment string to stdout
 * Return: 0
 */

void print_env(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}

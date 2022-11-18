#include "shell.h"

/**
 *execution - executes commands entered by users
 *@cp: command
 *@cmd:vector array of pointers to commands
 * Return: 0
 */

void execution(char *cp, char **cmd)
{
	char **env = environ;

	if (fork() == 0)
	{
		if (execve(cp, cmd, env) == -1)
		{
			free(cp);
			perror("./shell");
			exit(0);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

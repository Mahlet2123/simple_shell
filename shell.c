#include "shell.h"
/**
 * main - Entry point
 *
 * Return: always 0 (Success)
 */
int main(int ac, char **av, char *envp[])
{
	char **tokens = NULL;
	char *buffer = NULL;
	(void)envp, (void)av;
	
	if (ac < 1)
		return (-1);
	while (1)
	{
		prompt();
		buffer = _read_line();
		if (strncmp(buffer, "\n", 1) == 0)
			continue;
		tokens = _parse(buffer, "\n ");

		/**'0' if: fork and child process*/
		if (fork() == 0)
		{
			if (execve(tokens[0], tokens, NULL) == -1)
			{
				free(buffer);
				perror("./shell");
				exit(0);
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
		free(buffer);
		buffer = NULL;
	}
	return (0);
}

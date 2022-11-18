#include "shell.h"
/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * @envp: environment vector
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
		if (checker(tokens, buffer))
			continue;
		execution(tokens[0], tokens);
		free(buffer);
		buffer = NULL;
	}
	return (0);
}

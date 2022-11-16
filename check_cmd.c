#include "shell.h"

/**
 * check_cmd- checkes if command exists
 *@dir: list of directories
 *@tokens: command to be searched
 * Return: the right directory
 */

char *check_cmd(char **dir, char *token)
{
	int i;

	for (i = 0; dir[i] != NULL; i++)
	{
		str_concat(dir[i], "/");
		str_concat(dir[i], token);
		if (access(dir[i], F_OK) == 0)
		{
			exit(EXIT_SUCCESS);
		}
	}
	return (dir[i]);
}

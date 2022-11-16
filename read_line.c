#include "shell.h"

/**
 * _read_line- reads input from stdin
 *
 * Return: pointer to a buffer
 */

char *_read_line(void)
{
	char *buffer = NULL;
	size_t bufsize;

	if (getline(&buffer, &bufsize, stdin) == EOF)
	{
		free(buffer);
		exit(0);
	}
	return (buffer);
}

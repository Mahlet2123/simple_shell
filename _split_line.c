#include "shell.h"

/**
 * _parse- splittes line of strings
 * @str: string to be parsed
 * Return: array of splited strings
 */

char **_parse(char *str, char *delim)
{
	int i = 0, size = 1024;
	char **tokens = NULL;
	char *token;

	tokens = malloc(sizeof(char *) * size);
	if (tokens == NULL)
		exit(0);
	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
		if (i >= size)
		{
			size = size + size;
			tokens = realloc(tokens, size * sizeof(char *));
			if (tokens == NULL)
				exit(0);
		}
	}
	tokens[i] = NULL;
	free(tokens);
	return (tokens);
}

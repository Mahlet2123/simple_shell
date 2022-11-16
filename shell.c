#include "shell.h"

/**
 * main - Entry point
 *
 * Return: always 0 (Success)
 */

extern char **environ;

int main(void)
{
	char **tokens = NULL;
	char *buffer = NULL;
	size_t bufsize;
	int i = 0;

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&buffer, &bufsize, stdin) == EOF)
		{
			free(buffer);
			exit(0);
		}
		if (strncmp(buffer, "\n", 1) == 0)
		{
			/**buffer = "\0";
			free(buffer);*/
			continue;
		}
		tokens = _parse(buffer, "\n ");

/**		char **new_envp = copy_envp(environ);
		char *_path = get_path(new_envp, "PATH");
		char **path_string = _parse(_path, "=");
		char **dir = _parse(path_string[1], ":");
		for (i = 0; dir[i] != NULL; i++)
		{
			str_concat(dir[i], "/");
			str_concat(dir[i], tokens[0]);
			if (access(dir[i], F_OK) == 0)
			{
				exit(EXIT_SUCCESS);
			}
		}*/
			
		if (fork() == 0)
		{
			if (execve(tokens[i], tokens, NULL) == -1)
			{
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

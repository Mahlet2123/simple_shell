#include "shell.h"
/**
 * main - Entry point
 *
 * Return: always 0 (Success)
 */
int main(void)
{
	char **tokens = NULL;
	char *buffer = NULL;
	int i = 0;

	while (1)
	{
		printf("#cisfun$ ");
		buffer = _read_line();
		if (strncmp(buffer, "\n", 1) == 0)
			continue;
		tokens = _parse(buffer, "\n ");
/**
*		char **new_envp = copy_envp(environ);
*		char *_path = get_path(new_envp, "PATH");
*		char **path_string = _parse(_path, "=");
*		char **dir = _parse(path_string[1], ":");
*		char *rgt_dir = check_cmd(dir, tokens)
*/
		/**'0' if: fork and child process*/	
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

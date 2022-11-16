#include "shell.h"

/**
 * copy_envp- copies the enviroment list
 * @envp: a double pointer to the enviroment list
 * Return:pointer to the new string array
 */

char **copy_envp(char **envp)
{
	int i;
	char **new_envp = NULL;

	for (i = 0; envp[i] != NULL; i++)
	{
		new_envp[i] = malloc(sizeof(char *) * _strlen(envp[i] + 1));
		if (new_envp[i] == NULL)
		{
			exit(EXIT_FAILURE);
		}
		_strcpy(new_envp[i], envp[i]);
	}
	return (new_envp);
}

/**
 * get_path- to get the PATH string
 * @new_envp: newly copied enviroment list
 * @path: pointer to a string to be searched
 * Return: a pointer to the PATH string
 */

char *get_path(char **new_envp, char *path)
{
	char *_path = NULL;
	int i;

	for (i = 0; new_envp != NULL; i++)
	{
		if (strncmp(new_envp[i], path, _strlen(path)) == 0)
		{
			_strcpy(_path, new_envp[i]);
		}
	}
	return (_path);
}



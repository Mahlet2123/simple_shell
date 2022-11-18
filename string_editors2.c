#include "shell.h"

/**
 * _strcmp- compares two strings
 * @s1: string 1
 * @s2: string 2
 *Return: value
 */

int _strcmp(char *s1, char *s2)
{
	int value = 0, i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		value = s1[i] - s2[i];
		if (value != 0)
		{
			break;
		}
	}
	return (value);
}

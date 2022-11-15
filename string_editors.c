#include "shell.h"

/**
 *_strlen - returns the length of a string
 *
 *@s: string
 *
 * Return: 0
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len = len + 1;
		s++;
	}
	return (len);
}

/**
 * _strcpy - copies the string
 *
 *@src: source string
 *@dest: destination string
 *
 *Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; ++i)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * str_concat- concatenates two strings
 * @s1: first string
 * @s2: second string
 * Return: NULL (on failure)
 */

char *str_concat(char *s1, char *s2)
{
	char *s;
	int i;
	int l1 = strlen(s1);
	int l2 = strlen(s2);

	if (s1 == NULL)
	{
		s1[0] = '\0';
	}
	if (s2 == NULL)
	{
		s2[0] = '\0';
	}
	s = malloc(sizeof(char) * (l1 + l2 + 1));
	if (s == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < l1; i++)
	{
		s[i] = s1[i];
	}
	return (s);
}

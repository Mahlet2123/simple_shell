#include <stdio.h>

/**
 *main - entry point
 *Return: 0
 */

int main(void)
{
	int x;

	for (x = 97; x <= 122; x++)
	{
		if (x != 113 && x != 101)
			putchar(x);
	}
	putchar(10);
	return (0);
}

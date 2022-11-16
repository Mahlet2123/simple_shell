#include "shell.h"

/**
 *
 */

void prompt(void)
{
	write(STDIN_FILENO, "#cisfun$ ", 9);
}

#include "shell.h"

/**
 *prompt- writes the prompt
 *Returns: void
 */

void prompt(void)
{
	write(STDIN_FILENO, "#cisfun$ ", 9);
}

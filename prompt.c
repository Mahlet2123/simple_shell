#include "shell.h"

/**
 *prompt- writes the prompt
 *Returns: void
 */

void prompt(void)
{
	/**if (isatty(STDIN_FILENO))*/
	write(STDIN_FILENO, "#cisfun$ ", 9);
}

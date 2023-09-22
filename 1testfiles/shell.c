#include "shell.h"

/**
 * main - entry point
 * Return: 0 (Success)
 */

int main(void)
{
	bool isShellRunning = true;

	if (isatty(STDIN_FILENO))
	{
		while (isShellRunning)
		{
			interactive_mode();
		}
	}
	else
	{
		non_interactive_mode();
	}
	return (0);
}

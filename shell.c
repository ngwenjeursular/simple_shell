#include "shell.h"

/**
 * main - entry point
 * Return: 0 (Success)
 */

int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		interactive_mode();
	}
	else
	{
		non_interactive_mode();
	}
	return (0);
}

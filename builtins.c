#include "shell.h"

/**
 * exit_shell - func to exit the shell
 * Return: Nothing
 */

void exit_shell(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * exit_shell_with_status - exit shell with a specific status
 * @status: integer status code
 * Return: Nothing
 */

void exit_shell_with_status(int status)
{
	exit(status);
}

/**
 * print_environment - print the current environment
 * Return: Nothing
 */

void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		_puts(*env);
		_putchar('\n');
		env++;
	}
}

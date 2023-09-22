#include "shell.h"

/**
 * handle_setenv - handles the custom setenv function
 * @args: the arguments
 * Return: 1 if the buitin was handled as a command
 */
int handle_setenv(char **args)
{
	if (args[1] != NULL && args[2] != NULL)
	{
		my_setenv(args[1], args[2]);
	}
	else
	{
		_puts("Usage: my_setenv VARIABLE VALUE\n");
	}
	return (1);
}

/**
 * handle_unsetenv - handles the custom unsetenv function
 * @args: the arguments
 * Return: 1 if the builtin was handled as a command
 */
int handle_unsetenv(char **args)
{
	if (args[1] != NULL)
	{
		my_unsetenv(args[1]);
	}
	else
	{
		_puts("Usage: my_unsetenv VARIABLE\n");
	}
	return (1);
}

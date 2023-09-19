#include "shell.h"

/**
 * handle_builtin - handles buitin commands
 * @args: double pointer to arguments
 * Return: 0 if command was not handled as a builtin
 */

int handle_builtin(char **args)
{
	int status;

	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			status = atoi(args[1]);
			exit_shell_with_status(status);
		}
		else
		{
			exit_shell();
		}
		return (1);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_environment();
		return (1);
	}
	else if (strcmp(args[0], "my_setenv") == 0)
	{
		return (handle_setenv(args));
	}
	else if (strcmp(args[0], "my_unsetenv") == 0)
	{
		return (handle_unsetenv(args));
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		change_dir(args);
		return (1);
	}
	return (0);
}

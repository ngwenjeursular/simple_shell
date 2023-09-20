#include "shell.h"

/**
 * execute_command - responsible for executing the comand
 * @args: arguments
 * Return: Nothing
 */

void execute_command(char **args)
{
	if (strchr(args[0], '/') != NULL)
		execute_full_path(args);
	else
		execute_in_path(args);
}

/**
 * execute_full_path - executes command when full path is provided
 * @args: the arguments
 * Return: Nothing
 */

void execute_full_path(char **args)
{
	if (execve(args[0], args, environ) == -1)
	{
		perror("execve");
		exit(127);
	}
}

/**
 * execute_in_path - looks for and executes command in the PATH
 * @args: the arguments
 * Return: Nothing
 */

void execute_in_path(char **args)
{
	char *path = get_env_variable("PATH");
	char path_copy[MAX_PATH_LENGTH];
	char path_with_command[MAX_PATH_LENGTH];
	char *dir;
	int cmd_not_found = 1;


	if (path == NULL || *path == '\0')
	{
		path = ".";
	}
	strncpy(path_copy, path, sizeof(path_copy));
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		if (parse_path(path_with_command, dir, args[0]) == NULL)
		{
			perror("command path too long");
			exit(127);
		}
		if (access(path_with_command, X_OK) == 0)
		{
			if (execve(path_with_command, args, environ) == -1)
			{
				perror("execve");
				exit(127);
			}
			cmd_not_found = 0;
		}
		dir = strtok(NULL, ":");
	}
	if (cmd_not_found)
	{
		_puts("./hsh: ");
		_puts("1: ");
		_puts(args[0]);
		_puts(": not found\n");
		exit(127);
	}
}

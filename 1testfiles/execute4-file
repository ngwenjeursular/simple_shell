#include "shell.h"

/**
 * execute - main entry point of execution
 * @args: double pointer to the arguments
 * Return: Nothing
 */

void execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		execute_command(args);
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(127);
	}
	else
	{
		wait_for_child(pid, &status);
	}
}

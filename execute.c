#include "shell.h"

/**
 * execute - func to execute commands
 * @args: double pointer to the arguments
 * Return: 0 on Success
 */

int execute(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);

		}
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

		if (wpid == -1)
		{
			perror("waitpid");
			return (-1);
		}
	}
	return (0);
}

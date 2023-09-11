#include "shell.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: argument vector
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *userResponse, **args;
	int status;

	while (true)
	{
		user_Response = display_prompt();
		args = parse_input(user_Response);

		if (args[0] == NULL)
		{
			free(user_Response);
			free(args);
			continue;
		}
		status = execute(args);

		free(user_Response);
		free(args);
	}
	return (0);
}

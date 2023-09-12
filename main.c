#include "shell.h"

/**
 * main - entry point
 * Return: 0 (Success)
 */
int main(void)
{
	char *user_Response, **args;

	if (isatty(STDIN_FILENO))
	{
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
			execute(args);

			free(user_Response);
			free(args);
		}
	}
	else
	{
	}
	return (0);
}

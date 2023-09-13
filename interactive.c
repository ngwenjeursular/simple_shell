#include "shell.h"

/**
 * interactive_mode - handles interactive mode
 * Return: Nothing
 */

void interactive_mode(void)
{
	char *user_Response, **args;

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

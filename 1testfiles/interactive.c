#include "shell.h"

/**
 * interactive_mode - handles interactive mode
 * Return: Nothing
 */

void interactive_mode(void)
{
	char *user_Response = NULL;
	char **args;

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
		if (user_Response[_strlen(user_Response) - 1] == '\n')
			user_Response[_strlen(user_Response) - 1] = '\0';

		if (!handle_builtin(args))
			execute(args);

		free(user_Response);
		free(args);
	}
}

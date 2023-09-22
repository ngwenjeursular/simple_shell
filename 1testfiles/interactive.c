#include "shell.h"

/**
 * interactive_mode - handles interactive mode
 * Return: Nothing
 */

void interactive_mode(void)
{
	char *user_Response = NULL;
	char **args;
/*	int i;*/

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
		/*if (user_Response[_strlen(user_Response) - 1] == '\n')
			user_Response[_strlen(user_Response) - 1] = '\0';*/

		if (!handle_builtin(args))
		{
			execute(args);
/*			free(args);*/
		}

		free(user_Response);
		free(args);
	}
	free(user_Response);
	free(args);
/*	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
		free(user_Response);
	}
	free_args(args);*/
}
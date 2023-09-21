#include "shell.h"

/**
 * non_interactive_mode- handles non interactive mode
 * Return: Nothing
 */

void non_interactive_mode(void)
{
	char *user_Response = NULL;
	char **args;
	size_t input_line_size = 0;
	ssize_t nchars_read;

	while ((nchars_read = getline(&user_Response, &input_line_size, stdin)) != -1)
	{
		if (user_Response[nchars_read - 1] == '\n')
		{
			user_Response[nchars_read - 1] = '\0';
		}
		args = parse_input(user_Response);
		if (args[0] == NULL)
		{
			free(args);
			continue;
		}

		execute(args);
		free(args);
	}
	free(user_Response);
}

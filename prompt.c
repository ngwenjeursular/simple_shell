#include "shell.h"

/**
 * display_prompt - func to display prompt
 * Return: pointer to a character
 */
char *display_prompt(void)
{
	char *user_Response;
	size_t len = 0;
	ssize_t nchars_read;

	_puts("> ");
	nchars_read = getline(&user_Response, &len, stdin);

	if (nchars_read == -1 ? (perror("getline"), free(user_Response), 1) : 0)
	{
		return (NULL);
	}

	if (nchars_read == 0)
	{
		_puts("Exiting...\n");
		free(user_Response);
		exit(EXIT_SUCCESS);
	}

	if (user_Response[nchars_read - 1] == '\n')
	{
		user_Response[nchars_read - 1] = '\0';
	}

	return (user_Response);
}

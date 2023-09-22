#include "shell.h"

/**
 * display_prompt - func to display prompt
 * Return: pointer to a character
 */
char *display_prompt(void)
{
	char *prompt = "#cisfun$ ";
	char *user_Response = NULL;
	size_t len = 0;
	ssize_t nchars_read;

	if (isatty(STDIN_FILENO))
	{
		_puts(prompt);
	}
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

	return (user_Response);
}

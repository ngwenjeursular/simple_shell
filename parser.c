#include "shell.h"

/**
 * parse_input - parses input ;)
 * @user_Response: input to be parsed
 * Return: a double pointer to a character
 */
char **parse_input(char *user_Response)
{
	char **args = malloc(sizeof(char *) * MAX_NO_ARGS);
	int max_args = MAX_NO_ARGS;
	char *delimiters = " \n\t,;";
	char *token;
	int no_of_args = 0;

	if (args == NULL)
	{
		perror("memory allocation err");
		exit(127);
	}
	token = strtok(user_Response, delimiters);

	while (token != NULL)
	{
		args[no_of_args] = strdup(token);
		if (args[no_of_args] == NULL)
		{
			perror("memory allocation failed");
			exit(127);
		}
		no_of_args++;

		if (no_of_args >= max_args)
		{
			max_args += MAX_NO_ARGS;
			args = realloc(args, max_args * sizeof(char *));
			if (args == NULL)
			{
				perror("mem allocation error");
				exit(127);
			}
		}
		token = strtok(NULL, delimiters);
	}
	args[no_of_args] = NULL;
	return (args);
}

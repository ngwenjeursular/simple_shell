#include "shell.h"

/**
 * parse_input - parses input ;)
 * @user_Response: input to be parsed
 * Return: a double pointer to a character
 */
char **parse_input(char *user_Response)
{
	char **args = malloc(sizeof(char *) * MAX_NO_ARGS);
	char *delimiters = " \n\t,;";
	char *token;
	int no_of_args = 0, max_args = MAX_NO_ARGS;

	if (args == NULL)
	{
		free(args);
		perror("memory allocation err");
		exit(EXIT_FAILURE);
	}
	token = strtok(user_Response, delimiters);
	while (token != NULL)
	{
		args[no_of_args] = strdup(token);
		if (args[no_of_args] == NULL)
		{
			free(args);
			perror("memory allocation failed");
			exit(EXIT_FAILURE);
		}
		no_of_args++;
		if (no_of_args > 1)
		{
			free(args[no_of_args - 2]);
		}
		if (no_of_args >= max_args)
		{
			max_args += MAX_NO_ARGS;
			args = _realloc(args, max_args * sizeof(char *));
			if (args == NULL)
			{
				perror("mem allocation error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delimiters);
	}
	args[no_of_args] = NULL;
	return (args);
}

/**
* free_args - frees the memory allocated for args array.
* @args: double pointer to a character array.
*
* Return: void
*/
void free_args(char **args)
{
	int i;

	if (args)
	{
		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
	}
}
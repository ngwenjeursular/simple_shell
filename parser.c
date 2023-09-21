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
	char **new_args;
	size_t new_size;

	if (args == NULL)
	{
		perror("memory allocation err");
		exit(EXIT_FAILURE);
	}
	token = strtok(user_Response, delimiters);

	while (token != NULL)
	{
		args[no_of_args] = strdup(token);
		if (args[no_of_args] == NULL)
		{
			perror("memory allocation failed");
			exit(EXIT_FAILURE);
		}
		no_of_args++;
		if (no_of_args >= max_args)
		{
			new_size = max_args * sizeof(char *);
			max_args += MAX_NO_ARGS;
			new_args = _realloc(args, new_size, max_args * sizeof(char *));
			if (new_args == NULL)
			{
				perror("mem allocation error");
				exit(EXIT_FAILURE);
			}
			args = new_args;
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

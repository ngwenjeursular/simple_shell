#include "shell.h"

/**
* split_line - Split a line into tokens.
* @line: Input line.
* @delim: Delimiter character.
* @tokens: Array to store the tokens.
* @max_tokens: Maximum number of tokens to split.
* Return: The number of tokens found.
*/
int split_line(char *line, char delim, char *tokens[], int max_tokens)
{
	int token_count = 0;
	char *token = strtok(line, &delim);

	while (token != NULL)
	{
		tokens[token_count++] = token;

		if (token_count >= max_tokens)
		{
			break;
		}

		token = strtok(NULL, &delim);
	}

	return (token_count);
}

#include "shell.h"

/**
* _getline - Read a line of input from stdin.
* @fp: File pointer (stdin in this case)
* Return: A dynamically allocated string containing the input line, or
* NULL on error or EOF
*/
char *_getline2(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, fp);
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}

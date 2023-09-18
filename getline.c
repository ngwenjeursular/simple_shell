#include "shell.h"

/**
* _getline - Read a line of input from the user via stdin.
* Return: The input line as a string
*/
char *_getline()
{
	int i, bufferSize = BUFSIZE, readCount;
	char currentChar = 0;
	char *inputBuffer;

	inputBuffer = malloc(bufferSize);
	if (inputBuffer == NULL)
	{
		free(inputBuffer);
		return (NULL);
	}

	for (i = 0; currentChar != EOF && currentChar != '\n'; i++)
	{
		fflush(stdin); /* to avoid unexpected buffer behaviour */
		readCount = read(STDIN_FILENO, &currentChar, 1);
		if (readCount == 0)
		{
			free(inputBuffer);
			exit(EXIT_SUCCESS);
		}
		inputBuffer[i] = currentChar;
		if (inputBuffer[0] == '\n')
		{
			free(inputBuffer);
			return ("\0");
		}
		if (i >= bufferSize)
		{
			inputBuffer = _realloc(inputBuffer, bufferSize, bufferSize + 1);
			if (inputBuffer == NULL)
			{
				return (NULL);
			}
		}
	}
	inputBuffer[i] = '\0';
	hastag_handle(inputBuffer);
	return (inputBuffer);
}

/**
* hashtag_handle - Remove everything after the first '#' character in  a str.
* @inputString: The input string to process.
* Return: nothing.
*/
void hashtag_handle(char *inputString)
{
	int i;

	for (i = 0; inputString[i] != '\0'; i++)
	{
		if (inputString[i] == '#')
		{
			inputString[i] = '\0';
			break;
		}
	}
}

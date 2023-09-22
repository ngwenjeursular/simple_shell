#include "main.h"

/**
 * prompt - Display Shell Prompt
 */
void prompt(void)
{
	_PRINT("$ ");
}
/**
 * print_error - Display Error Based on Command and How Many Time Shell Looped
 * @input:User Input
 * @counter:Simple Shell Count Loop
 * @argv:Program Name
 * Return: Void
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	_PRINT(argv[0]);
	_PRINT(": ");
	er = _itoa(counter);
	_PRINT(er);
	free(er);
	_PRINT(": ");
	_PRINT(input);
	_PRINT(": not found\n");
}

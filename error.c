#include "main.h"
/**
 *  _prerror - Print Custome Error
 * @argv:Program Name
 * @c:Error Count
 * @cmd:Command
 * Return: Void
 */
void _prerror(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	_PRINT(argv[0]);
	_PRINT(": ");
	_PRINT(er);
	_PRINT(": ");
	_PRINT(cmd[0]);
	_PRINT(": Illegal number: ");
	_PRINT(cmd[1]);
	_PRINT("\n");
	free(er);
}

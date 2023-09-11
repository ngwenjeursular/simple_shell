#include "shell.h"

/**
 * _puts - writesa string to stdout
 * @str: string to be printed
 * Return: Nothing
 */
void _puts(const char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}

/**
 * _putchar - used to write char to stsout
 * @c: char to print
 * Return: 1 (Succes), (-1) on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

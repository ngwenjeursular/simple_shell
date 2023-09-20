#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _strncpy - copy source string to destination string
* @dest: shows destination
* @src: shows source
* @n: shows integer
* Return: (dest)
*/
char *_strncpy(char *dest, char *src, int n)
{
	char *ptr = dest;

	/*Copy at most n characters from source to destination*/
	while (*src != '\0' && n > 0)
	{
		*ptr = *src;
		ptr++;
		src++;
		n--;
	}
	/* Fill the remaining space in destination with null bytes*/
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
	return (dest);
}
/**
* _strlen - return the length of a string
*@s: shows input string
*Return: length of string
*/
int _strlen(char *s)
{
	int length = 0;

	while (*(s + length) != '\0')
	{
		length++;
	}

	return (length);
}

/**
* _atoi - converts a string to integers
* @s: shows input string
*
*Return: integer
*/
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
/**
* _puts - prints a string, followed by a new line.
*@str: input string
*Return: no return
*/
void _puts(char *str)
{
	int length = 0;

	while (length >= 0)
	{
		if (str[length] == '\0')
		{
			_putchar('\n');
			break;
		}
		_putchar(str[length]);
		length++;
	}
}

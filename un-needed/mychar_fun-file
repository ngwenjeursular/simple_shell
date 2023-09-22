#include "shell.h"

/**
 * _memset - fills a specified mem region with a givn value
 * @dest: destination
 * @value: one that fills
 * @n: number of the bytes to be filled
 * Return: Nothing
 */
void *_memset(void *dest, int value, size_t n)
{
	unsigned char *p = dest;

	while (n > 0)
	{
		*p = (unsigned char)value;
		p++;
		n--;
	}
	return (dest);
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
int _strlen(const char *s)
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

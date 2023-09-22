#include "shell.h"

/**
* _strcat - joins the first string with second string.
* @dest: shows the destination.
* @src: shows the source.
* Return: pointer to dest.
*/
char *_strcat(char *dest, const char *src)
{
	char *ptr = dest;

	while (*ptr != '\0')
	{
		ptr++;
	}
	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';

	return (dest);
}
/**
*_strcpy - copies the string pointed to by src
*including the terminating  '\0', to the buffer pointed to by dest
*@dest: destination
*@src: source
*Return: the pointer to dest
*/
char *_strcpy(char *dest, const char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	return (dest);
}

/**
* _strchr - locates a character in a string
* @s: string
* @c: character
* Return: the pointer to the occurence of the character c or otherwise NULL
*/
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}
/**
* _strcmp - compare the first string with second string.
* @s1: shows first string
* @s2: shows second string
* Return: 0 if they are equal, another number if not
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0, cp = 0;

	while (cp == 0)
	{
		if ((*(s1 + i) == '\0') && (*(s2 + i) == '\0'))
			break;
		cp = *(s1 + i) - *(s2 + i);
		i++;
	}
	return (cp);
}
/**
* _strdup -returns a pointer to duplicate string of str
* @str: string
* Return: pointer to duplicate string
*/
char *_strdup(char *str)
{
	char *duplicate;

	if (str == NULL)
	{
		return (NULL);
	}
	/*allocation of memory for the duplicated string*/
	duplicate = (char *)malloc(_strlen(str) + 1);

	if (duplicate == NULL)
	{
		return (NULL);
	}
	_strcpy(duplicate, str);
	return (duplicate);
}


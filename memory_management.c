#include "shell.h"

/**
* free_all - Free memory for an array of strings and a string.
* @cmd: Array of strings.
* @line: A string.
* Return: nothing
*/
void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
}

/**
* _calloc - Allocate memory for an array and initialize with null bytes.
* @size: Size of the memory block to allocate.
*
* Return: A pointer to the allocated memory block.
*/
void *_calloc(size_t size)
{
	void *block = malloc(size);

	if (block == NULL)
		return (NULL);

	_memset(block, 0, size);
	return (block);
}

/**
* _realloc - Reallocate memory block with specified size.
* @ptr: Pointer to the memory block to be reallocated.
* @new_size: New size of the memory block.
* Return: A pointer to the reallocated memory block.
*/
void *_realloc(void *ptr, size_t new_size)
{
	void *result;

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	result = malloc(new_size);

	if (result == NULL)
		return (NULL);

	if (ptr != NULL)
	{
		_memcpy(result, ptr, new_size);
		free(ptr);
	}


	return (result);
}

/**
* _memcpy - Copy bytes from source to destination.
* @dest: Destination pointer.
* @src: Source pointer.
* @n: Number of bytes to copy.
* Return: A pointer to the destination.
*/
char *_memcpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
* fill_an_array - Fill an array with a constant byte.
* @a: A pointer to the memory block to be filled.
* @el: An integer representing the byte to fill the array with.
* @len: The number of elements in the array.
* Return: A pointer to the filled memory block.
*/
void *fill_an_array(void *a, int el, size_t len)
{
	char *ptr = a;
	size_t i = 0;

	while (i < len)
	{
		*ptr = (char)el; /* fill each element with the specified byte*/
		ptr++;
		i++;
	}

	return (a);
}

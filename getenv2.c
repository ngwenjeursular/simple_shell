#include "shell.h"

/**
 * get_env_variable - gets the environment variable
 * @var: a constant variable
 * Return: pointer to a char
 */

char *get_env_variable(const char *var)
{
	size_t len = strlen(var);
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(var, environ[i], len) == 0 && environ[i][len] == '=')
			return (&environ[i][len + 1]);
	}
	return (NULL);
}

#include "shell.h"

/**
 * exit_shell - func to exit the shell
 * Return: Nothing
 */

void exit_shell(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * exit_shell_with_status - exit shell with a specific status
 * @status: integer status code
 * Return: Nothing
 */

void exit_shell_with_status(int status)
{
	exit(status);
}

/**
 * print_environment - print the current environment
 * Return: Nothing
 */

void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		_puts(*env);
		_putchar('\n');
		env++;
	}
}

/**
 * my_setenv - sets or updates an environment variable
 * @name: name of the environment variable
 * @value: value to set for the environment variable
 *
 * Return: Nothing
 */
void my_setenv(const char *name, const char *value)
{
	char *new_env;
	size_t new_env_len;
	char **env = environ;
	int i;

	if (name == NULL || value == NULL)
	{
		_puts("Usage: setenv VARIABLE VALUE\n");
		return;
	}
	new_env_len = strlen(name) + strlen(value) + 2;
	new_env = malloc(new_env_len);
	if (new_env == NULL)
	{
		_puts("Memory allocation err\n");
		return;
	}
	strcpy(new_env, name);
	strcat(new_env, "=");
	strcat(new_env, value);
	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(name, env[i], strlen(name)) == 0 && env[i][strlen(name)] == '=')
		{
			env[i] = strdup(new_env);
			if (env[i] == NULL)
			{
				_puts("Memory allocation error\n");
			}
			free(new_env);
			return;
		}
	}
	environ[i] = strdup(new_env);
	if (environ[i] == NULL)
	{
		_puts("Memory allocation error\n");
	}
	free(new_env);
}


/**
 * my_unsetenv - removes an environment variable
 * @name: name of the env variable to remove
 * Return: Nothing
 */
void my_unsetenv(const char *name)
{
	int i, j;

	if (name == NULL)
	{
		_puts("Usage: unsetenv VARIABLE\n");
		return;
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], strlen(name)) == 0)
		{
			free(environ[i]);
			for (j = i; environ[j + 1] != NULL; j++)
				environ[j] = environ[j + 1];
			environ[j] = NULL;
			return;
		}
	}
}

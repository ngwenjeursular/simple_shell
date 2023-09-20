#include "main.h"

/**
* initialize_shell - Initializes the shell environment.
* @env: Pointer to the shell environment struct.
* Return: no return.
*/
void initialize_shell(ShellEnvironment *env)
{
	env->bufsize = 0;
	env->buffer = NULL;
}

/**
* cleanup_shell - Cleans up the shell environment.
* @env: Pointer to the shell environment struct.
* Return: no return.
*/
void cleanup_shell(ShellEnvironment *env)
{
	if (env->buffer != NULL)
	{
		free(env->buffer);
	}
}

/**
* display_prompt - Displays the shell prompt.
*
* Return: nothing.
*/
void display_prompt(void)
{
	_putchar('#');
	_putchar(' ');
	_putchar('c');
	_putchar('i');
	_putchar('s');
	_putchar('f');
	_putchar('u');
	_putchar('n');
	_putchar('$');
	_putchar(' ');
}
/**
* read_input - Reads a line of input from the user.
* @env: Pointer to the shell environment struct.
* Return: 0 on success, -1 on error.
*/
int read_input(ShellEnvironment *env)
{
	ssize_t line_size;

	line_size = getline(&(env->buffer), &(env->bufsize), stdin);

	if (line_size == -1)
	{
		if (feof(stdin))
		{
			cleanup_shell(env);

			if (isatty(STDIN_FILENO))
			{
				_putchar('\n');
			}
			return (-1);
		}
		perror("getline");
		return (-1);
	}

	if (env->buffer[line_size - 1] == '\n')
		env->buffer[line_size - 1] = '\0';

	return (0);
}

/**
* execute_command - Executes a command entered by the user.
* @env: Pointer to the shell environment struct.
* Return: 0 on success, -1 on error.
*/
int execute_command(ShellEnvironment *env)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	else if (pid == 0)
	{
		char **argv = (char **)malloc(sizeof(char *) * 2);

		if (argv == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}

		argv[0] = env->buffer;
		argv[1] = NULL;

		execve(env->buffer, argv, environ);
		return (-1);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		return (0);
	}
}

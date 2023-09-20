#include "main.h"

/**
* initialize_shell - Initializes the shell structure.
* @shell: Pointer to the Shell structure.
* Return: no return.
*/
void initialize_shell(struct Shell *shell)
{
	memset(shell->command, 0, sizeof(shell->command));
}

/**
* display_prompt - Display the shell prompt.
*
* Return: no return.
*/
void display_prompt(void)
{
	printf("#cisfun$ ");
}

/**
* read_user_input - Read user input into the shell structure.
* @shell: Pointer to the Shell structure.
*
* Return: no return.
*/
void read_user_input(struct Shell *shell)
{
	size_t len;

	if (fgets(shell->command, sizeof(shell->command), stdin) == NULL)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}

	len = strlen(shell->command);

	if (len > 0 && shell->command[len - 1] == '\n')
	{
		shell->command[len - 1] = '\0';
	}
}

/**
* execute_command - Execute the user's command.
* @shell: Pointer to the Shell structure.
*
* Return: no return.
*/
void execute_command(struct Shell *shell)
{
	char **args;
	pid_t child_pid;

	if (strcmp(shell->command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	child_pid = fork();

	if (child_pid < 0)
	{
		perror("Fork failed");
		return;
	} else if (child_pid == 0)
	{
		args = malloc(3 *sizeof(char *));

		if (args == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		args[0] = shell->command;
		args[1] = NULL;
		args[2] = NULL;

		if (execve(shell->command, args, environ) == -1)
		{
			perror("Command not found");
			exit(EXIT_FAILURE);
		}
	} else
	{
		int status;

		waitpid(child_pid, &status, 0);
	}
}

/**
* main - Entry point of the shell.
* @argc: Argument count (unused).
* @argv: Argument vector (unused).
* Return: Always 0.
*/
int main(void)
{
	struct Shell shell;

	while (1)
	{
		initialize_shell(&shell);
		display_prompt();
		read_user_input(&shell);
		execute_command(&shell);
	}

	return (0);
}

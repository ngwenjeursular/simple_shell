#include "main.h"

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
	size_t input_len;

	if (fgets(shell->input, sizeof(shell->input), stdin) == NULL)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}

	input_len = strlen(shell->input);

	if (input_len > 0 && shell->input[input_len - 1] == '\n')
	{
		shell->input[input_len - 1] = '\0';
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
	if (strcmp(shell->input, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	pid_t child_pid = fork();

	if (child_pid < 0)
	{
		perror("Fork failed");
		return;
	} else if (child_pid == 0)
	{
		char *args[] = {shell->input, NULL};

		if (execve(shell->input, args, environ) == -1)
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
* main - checks the code.
*
* Return: no return.
*/
int main(void)
{
	struct Shell shell;

	while (1)
	{
		display_prompt();
		read_user_input(&shell);
		execute_command(&shell);
	}

	return (0);
}

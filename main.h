#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
#define MAX_COMMAND_LENGTH 100

/**
* struct Shell - A structure to represent the shell and its command.
* @command: The command entered by the user.
*/
struct Shell
{
	char command[MAX_COMMAND_LENGTH];
};

void initialize_shell(struct Shell *shell);
void display_prompt(void);
void read_user_input(struct Shell *shell);
void execute_command(struct Shell *shell);
#endif

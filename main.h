#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

extern char **environ;

/**
* struct Shell - A structure to hold shell -related data
* @input: Array to store user input
*/
struct Shell
{
	char input[MAX_INPUT_SIZE];
};

void display_prompt(void);
void read_user_input(struct Shell *shell);
void execute_command(struct Shell *shell);
#endif

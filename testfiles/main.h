#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>

extern char **environ;

/**
* struct ShellEnvironment - Represents the shell environment.
* @buffer: Pointer to a character buffer for storing user input.
* @bufsize: The size of the buffer.
*/
typedef struct ShellEnvironment
{
	char *buffer;
	size_t bufsize;
} ShellEnvironment;

int _putchar(char c);
void initialize_shell(ShellEnvironment *env);
void cleanup_shell(ShellEnvironment *env);
void display_prompt(void);
int read_input(ShellEnvironment *env);
int execute_command(ShellEnvironment *env);
#endif

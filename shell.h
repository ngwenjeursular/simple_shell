#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define MAX_NO_ARGS 64

void _puts(const char *str);
int _putchar(char c);
int execute(char **args);
char **parse_iput(char *user_Response);
char *display_prompt(void);


#endif

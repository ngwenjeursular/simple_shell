#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

#define MAX_NO_ARGS 64
#define MAX_PATH_LENGTH 1024
#define BUFFER_SIZE 1024


/*writes.c*/
void _puts(const char *str);
int _putchar(char c);

/*parser.c*/
char **parse_input(char *user_Response);

/*prompt.c*/
char *display_prompt(void);

/*interactive.c*/
void interactive_mode(void);

/*non-interactive.c*/
void non_interactive_mode(void);

/*global varaiable*/
extern char **environ;

/*not needed*/
char *look4cmd_in_path(const char *cmd);
char *_getenv(const char *env_name);
void print_command_not_found(const char *command);

/*custom getenv - getenv2.c*/
char *get_env_variable(const char *var);

/*path_parser.c*/
char *parse_path(char *path, char *dir, char *command);

/*execute4.c*/
void execute(char **args);

/*builtins.c*/
void exit_shell(void);
void exit_shell_with_status(int status);
void print_environment(void);

/*handle_builtins.c*/
int handle_builtin(char **args);

/*for_the_paths.c*/
void execute_command(char **args);
void execute_full_path(char **args);
void execute_in_path(char **args);

/*waitpid.c*/
void wait_for_child(pid_t pid, int *status);

/*builtins.c*/
void my_setenv(const char *name, const char *value);
void my_unsetenv(const char *name);

/*change_dir.c*/
void change_dir(char **args);

/*handle_setUnsetenv.c*/
int handle_setenv(char **args);
int handle_unsetenv(char **args);

/* memory management.c */
void *fill_an_array(void *a, int el, size_t len);
void free_all(char **cmd, char *line);
void *_calloc(unsigned int size);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, size_t new_size);

/* tokenizer.c */
char **tokenize(char *lineptr);

/* getline */
char *_getline_command(void);

/*more_fun.c*/
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);

/*more_mychar_fun.c*/
int _strncmp(const char *s1, const char *s2, size_t n);
int _isalpha(int c);
void reverse_array(char *a, int n);
int intlen(int num);
char *_itoa(unsigned int n);

/*mychar_fun.c*/
char *_strncpy(char *dest, char *src, int n);
int _strlen(const char *s);
int _atoi(char *s);
void *_memset(void *dest, int value, size_t n);

#endif

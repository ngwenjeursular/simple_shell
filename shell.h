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
void *_calloc(size_t size);
char *_memcpy(char *dest, const char *src, size_t n);
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/* _strtok.c */
int split_line(char *line, char delim, char *tokens[], int max_tokens);

/* getline */
/*char *_getline(FILE *fp);*/
char *_getline(void);

/* hashtag handle */
void hashtag_handle(char *inputString);

#endif

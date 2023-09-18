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
#include <sys/time.h>

#define MAX_NO_ARGS 64
#define MAX_PATH_LENGTH 1024
#define BUFFER_SIZE 1024

void _puts(const char *str);
int _putchar(char c);
char **parse_input(char *user_Response);
char *display_prompt(void);
void interactive_mode(void);
void non_interactive_mode(void);
extern char **environ;
char *look4cmd_in_path(const char *cmd);
char *_getenv(const char *env_name);
void print_command_not_found(const char *command);
char *get_env_variable(const char *var);
char *parse_path(char *path, char *dir, char *command);
void execute(char **args);
void exit_shell(void);
void exit_shell_with_status(int status);
void print_environment(void);
int handle_builtin(char **args);
void execute_command(char **args);
void execute_full_path(char **args);
void execute_in_path(char **args);
void wait_for_child(pid_t pid, int *status);

/* memory managment.c */
void *fill_an_array(void *a, int el, size_t len);
void free_all(char **cmd, char *line);
void *_calloc(size_t size);
char *_memcpy(char *dest, const char *src, size_t n);
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/* _strtok.c */
int split_line(char *line, char delim, char *tokens[], int max_tokens);

/* getline */
char *_getline(FILE *fp);
char *_getline();

/* hashtag handle */
void hashtag_handle(char *inputString);
#endif

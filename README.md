# Simple shell

This is a group project. This project is an attempt to create a basic minimalistic version of a unix-like shell, a fundamental concept on most modern
 operating systems
The primary goal here is to gain a deeper understanding of how shells work. By building a simple shell we aim to:
- learn about process creation and management
- understand how to parse and execute user commands
- explore concepts like I/O redirection and pipes
- gain insights into POSIX standards and system calls
- Enhance our programming skills


## FEATURES
* command execution
* Input Output redirection
* Support for chaining multiple commands
* Execution of processes in the background

## List of Allowed Functions and System Calls

- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

## Compilation

To compile your shell, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


your simple UNIX command interpreter should work in both interactive and non-interactive mode

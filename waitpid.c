#include "shell.h"

/**
 * wait_for_child - waits for child process to terminate
 * @pid: process id
 * @status: status code
 * Return: Nothing
 */

void wait_for_child(pid_t pid, int *status)
{
	pid_t wpid;

	do {
		wpid = waitpid(pid, status, WUNTRACED);
	} while (!WIFEXITED(*status) && !WIFSIGNALED(*status));

	if (wpid == -1)
	{
		perror("waitpid");
		exit(127);
	}
}

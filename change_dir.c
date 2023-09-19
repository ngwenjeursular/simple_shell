#include "shell.h"

/**
 * change_dir - Change the cuurent dir of the process
 * @args: arr of command arguments
 * Return: Nothing
 */
void change_dir(char **args)
{
	char current_dir[PATH_MAX];
	char *home = get_env_variable("HOME"), *new_dir;

	if (args[1] == NULL)
	{
		new_dir = home;
	}
	else if (strcmp(args[1], "-") == 0)
	{
		new_dir = get_env_variable("OLDPWD");
	}
	else
	{
		new_dir = args[1];
	}
	if (new_dir == NULL)
	{
		_puts("cd: HOME not set\n");
	}
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("getcwd");
		return;
	}

	my_setenv("OLDPWD", current_dir);

	if (chdir(new_dir) != 0)
	{
		perror("chdir");
		return;
	}
	my_setenv("PWD", new_dir);
}

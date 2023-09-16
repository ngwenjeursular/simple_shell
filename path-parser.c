#include "shell.h"

/**
 * parse_path - parses the path
 * @path: path to be parsed
 * @dir: directory
 * @command: ah yes the command :)
 *
 * Return: pointer to the constructed path
 */
char *parse_path(char *path, char *dir, char *command)
{
	size_t dir_len = strlen(dir);
	size_t command_len = strlen(command);

	if (dir_len + command_len + 2 > MAX_PATH_LENGTH)
		return (NULL);

	strcpy(path, dir);
	strcpy(path + dir_len, "/");
	strcpy(path + dir_len + 1, command);

	return (path);
}

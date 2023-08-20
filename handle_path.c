#include "main.h"

/**
 * check_path - a function that check if command existe in all path
 *                           with given as command.
 * @ptr: a pointer to stracture.
 */
void check_path(shell *ptr)
{
	char *paths, *one_path, *file_path;
	size_t len_file_path;

	if (ptr->array[0][0] != '/' && ptr->array[0][1] != '\0')
	{
		if (_strlen(_getenv("PATH", ptr->env)) == 0)
			return;
		paths = malloc(_strlen(_getenv("PATH", ptr->env)) + 1);
		if (!paths)
		{
			free(paths);
			return;
		}
		_strcpy(paths, _getenv("PATH", ptr->env));
		if (paths)
		{
			one_path = strtok(paths, ":");
			while (one_path)
			{
				len_file_path = _strlen(ptr->array[0]) + _strlen(one_path) + 2;
				file_path = malloc(len_file_path);
				_strcpy(file_path, one_path);
				_strcat(file_path, "/");
				_strcat(file_path, ptr->array[0]);
				if (access(file_path, F_OK) == 0)
				{
					free(ptr->array[0]);
					ptr->array[0] = _strdup(file_path);
					free(file_path);
					break;
				}
				else
				{
					free(file_path);
					one_path = strtok(NULL, ":");
				}
			}
		}
		free(paths);
	}
}

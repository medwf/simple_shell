#include "main.h"

/**
 * handle_exit_env - a function that exit shell and print env.
 * @ptr: a pointer to structure.
 * @env: a double pointer that points to string of enviroment.
 * Return: 1 if Success, otherwise 0.
 */
int handle_exit_env(input *ptr, char **env)
{
	int i = 0;

	if (!_strcmp(ptr->array[0], "exit") && !ptr->array[1])
	{
		free_array(ptr);
		free(ptr->stored);
		exit(ptr->_exit);
	}

	if (!_strcmp(ptr->array[0], "env") && !ptr->array[1])
	{
		while (env[i])
		{
			write(STDOUT_FILENO, env[i], _strlen(env[i]));
			print("\n");
			i++;
		}
		return (1);
	}
	return (0);
}

#include "main.h"

/**
 * handle_exit_env - a function that exit shell and print env.
 * @ptr: a pointer to structure.
 * Return: 1 if Success, otherwise 0.
 */
int handle_exit_env(shell *ptr)
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
		while (ptr->env[i])
		{
			write(STDOUT_FILENO, ptr->env[i], _strlen(ptr->env[i]));
			print("\n");
			i++;
		}
		return (1);
	}
	return (0);
}

#include "main.h"

/**
 * handle_exit_env - a function that exit shell and print env.
 * @ptr: a pointer to structure.
 * Return: 1 if Success, otherwise 0.
 */
int handle_exit_env(shell *ptr)
{
	int i = 0;

	/* exit with no argumment*/
	if (!_strcmp(ptr->array[0], "exit") && !ptr->array[1])
		free_array(ptr), free(ptr->stored), exit(ptr->_exit);
	else
	{
		/* exit with argument using my own _atoi to change string to integer*/
		/* and check if is number or not*/
		if (!_strcmp(ptr->array[0], "exit") && (_atoi(ptr->array[1]) != -1)
			&& !ptr->array[2])
		{
			ptr->_exit = atoi(ptr->array[1]);
			free_array(ptr), free(ptr->stored), exit(ptr->_exit);
		}
		if (!_strcmp(ptr->array[0], "exit") && (_atoi(ptr->array[1]) == -1)
			&& !ptr->array[2])
		{
			print_error(ptr, "Illegal number: ");
			write(STDERR_FILENO, ptr->array[1], _strlen(ptr->array[1]));
			write(2, "\n", 1), ptr->_exit = 2;
			return (1);
		}
	}

	if (!_strcmp(ptr->array[0], "env") && !ptr->array[1])
	{
		while (ptr->env[i])
		{
			write(STDOUT_FILENO, ptr->env[i], _strlen(ptr->env[i]));
			print("\n"), i++;
		}
		return (1);
	}
	return (0);
}

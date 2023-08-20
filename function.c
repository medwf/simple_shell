#include "main.h"

/**
 * free_array - a function free argumment.
 * @ptr: a pointer to structure input
 */
void free_array(shell *ptr)
{
	int i = 0;

	/* if av == NULL dont free and return*/
	if (!ptr->array)
		return;
	/* free av */
	while (ptr->array[i])
	{
		free(ptr->array[i]);
		ptr->array[i] = NULL;
		i++;
	}
	free(ptr->array);
}
/**
 * divide_arg - a function that divied a long sting to argument in av.
 * @ptr: a pointer to structure.
 */
void divide_arg(shell *ptr)
{
	int num_token = 0;
	char *token;

	ptr->array = malloc(sizeof(char *) * 2);
	ptr->array[0] = NULL;
	ptr->array[1] = NULL;

	token = strtok(ptr->stored, " ");
	while (token && token[0] != '#')
	{
		if (num_token == 0)
			ptr->array = _realloc(ptr->array, sizeof(char *) * 2,
					sizeof(char *) * (num_token + 2));
		if (num_token)
			ptr->array = _realloc(ptr->array, sizeof(char *) * ((num_token - 1) + 2),
					sizeof(char *) * (num_token + 2));
		if (!ptr->array)
		{
			free_array(ptr);
			free(ptr->stored);
			perror(ptr->name_shell);
			exit(EXIT_FAILURE);
		}
		ptr->array[num_token] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(ptr->array[num_token++], token);
		token = strtok(NULL, " ");
	}
	ptr->array[num_token] = NULL;
}

/**
 * handler - a function that handle with signal ctrl + c
 * @signal : integer.
 */
void handler(int __attribute__((unused)) signal)
{
	exit(EXIT_FAILURE);
}
/**
 * dte_space - delete wait space from stored (input string)
 *@str: pointers to stored.
 */

void dte_space(char *str)
{
	int i = 0, j = 0;

	while ((*(str + i) == ' ' || *(str + i) == '\t') && *(str + i))
		i++;
	while (*(str + i) && *(str + j))
	{
		*(str + j) = *(str + i);
		i++;
		j++;
	}
	*(str + j) = '\0';
}
/**
 * _realloc - reallocates a memory block using malloc and free.
 *@old_size: is the size, in bytes, of the allocated space for ptr.
 *@new_size: is the new size, in bytes of the new memory block.
 *@ptr:  is a pointer to the memory previously allocated.
 *Return: NULL or pointer.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i = 0;
	char *ptr_new;
	char *ptr_old;

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	ptr_new = malloc(new_size);
	if (ptr_new == NULL)
		return (NULL);

	ptr_old = ptr;
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			ptr_new[i] = ptr_old[i];
	}
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			ptr_new[i] = ptr_old[i];
	}
	free(ptr);
	return (ptr_new);
}

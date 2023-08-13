#include "main.h"

/**
 * free_array - a function free argumment.
 * @ptr: a pointer to structure input
 */
void free_array(input *ptr)
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
void divide_arg(input *ptr)
{
	int num_token = 0;
	char *token;

	ptr->array = malloc(sizeof(char *) * 2);
	ptr->array[0] = NULL;
	ptr->array[1] = NULL;

	token = strtok(ptr->stored, " \n");
	while (token)
	{
		ptr->array = realloc(ptr->array, sizeof(char *) * (num_token + 2));
		if (!ptr->array)
		{
			free_array(ptr);
			free(ptr->stored);
			perror(ptr->name_shell);
			exit(1);
		}
		ptr->array[num_token] = realloc(ptr->array[num_token],
		sizeof(char) * (strlen(token) + 1));
		strcpy(ptr->array[num_token++], token);
		token = strtok(NULL, " \n");
	}
	ptr->array[num_token] = NULL;
}

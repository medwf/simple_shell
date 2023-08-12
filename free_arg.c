#include "main.h"

/**
* free_arg - a function free argumment.
* @argv: an array of string.
*/
void free_arg(char **argv)
{
	int i = 0;

	if (!argv)
		return;
	else
	{
		while (argv[i] != NULL)
		{
			free(argv[i]);
			argv[i] = NULL;
			i++;
		}
		free(argv);
	}
}


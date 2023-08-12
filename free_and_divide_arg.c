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
	while (argv[i] != NULL)
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
}
/**
 * divide_arg - a function that divied a long sting to argument in av.
 * @std : pointer long string.
 * @av: an array of argument.
 * Return: array of argument (av);
 */
char **divide_arg(char **av, char *std)
{
	const char *delim = " ";
	int num_token;
	char *token = 0;

	av = malloc(sizeof(char *) * 2);
	av[0] = NULL;
	av[1] = NULL;

	token = strtok(std, delim);
	while (token)
	{
		av = realloc(av, sizeof(char *) * (num_token + 2));
		if (!av)
		{
			free_arg(av);
			free(std);
			perror("realloc");
			exit(1);
		}
		av[num_token] = realloc(av[num_token], sizeof(char) * (strlen(token) + 1));
		strcpy(av[num_token++], token);
		token = strtok(NULL, delim);
	}
	av[num_token] = NULL;

	return (av);
}

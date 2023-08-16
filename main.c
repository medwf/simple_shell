#include "main.h"

/**
 * main - Entry points.
 * Description: create a UNIX command line interpreter.
 * @argc: the number of argument.
 * @argv: an array of argumment.
 * Return: 0 Always Success, otherwise return 1.
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	input in;
	const char *prmt = "#cisfun$ ";
	size_t count = 0;

	init_struct(&in, argv[0]);
	signal(SIGINT, handler);
	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO))
			print(prmt);
		_getline(&in);
		if (in.stored && in.stored[0])
		{
			divide_arg(&in);
			if (access(in.array[0], F_OK) == -1)
				print_error(&in, count, "not found\n");
			else
				fork_execve(&in, count);
			free_array(&in);
		}
		free(in.stored);
	}
	return (0);
}

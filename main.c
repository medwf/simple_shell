#include "main.h"

/**
 * main - Entry points.
 * Description: create a UNIX command line interpreter.
 * @argc: the number of argument.
 * @argv: an array of argumment.
 * @env: an array of enviroment.
 * Return: 0 Always Success, otherwise return 1.
 */

int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	input in;
	size_t count = 0;

	init_struct(&in, argv[0]);
	signal(SIGINT, handler);
	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO))
			print("#cisfun$ ");
		_getline(&in);

		if (in.stored && in.stored[0])
		{
			divide_arg(&in);
			if (!handle_exit_env(&in, env))
			{
				check_path(&in, env);
				if (!((in.array[0][0] == '.' || in.array[0][0] == '/') &&
					access(in.array[0], F_OK) == 0))
				{
					print_error(&in, count, "not found\n");
					in._exit = 127;
				}
				else if (access(in.array[0], X_OK) != 0)
				{
					print_error(&in, count, "Permission denied\n");
					in._exit = 126;
				}
				else
					fork_execve(&in, count);
			}
			free_array(&in);
		}
		free(in.stored);
	}
	return (0);
}

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
	shell sh;

	init_struct(&sh, argv[0], env);
	signal(SIGINT, handler);
	while (++sh.count)
	{
		if (isatty(STDIN_FILENO))
			print("#cisfun$ ");
		get_command(&sh);
		if (_strlen(sh.stored))
		{
			divide_arg(&sh);
			if (!handle_exit_env(&sh))
			{
				check_path(&sh);
				if (!((sh.array[0][0] == '.' || sh.array[0][0] == '/') &&
							access(sh.array[0], F_OK) == 0))
				{
					print_error(&sh, "not found\n");
					sh._exit = 127;
				}
				else if (access(sh.array[0], X_OK) != 0)
				{
					print_error(&sh, "permission denied\n");
					sh._exit = 126;
				}
				else
					fork_execve(&sh);
			}
			free_array(&sh);
		}
		free(sh.stored);
	}
	return (sh._exit);
}

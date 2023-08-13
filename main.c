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
	int status = 0;
	ssize_t read;
	size_t len = 0;
	pid_t chlid_pid = 0;

	in.stored = NULL;
	in.array = NULL;
	in.name_shell = argv[0];

	while (1)
	{
		write(STDOUT_FILENO, prmt, strlen(prmt));
		len = 0;
		read = getline(&in.stored, &len, stdin);
		if (read == -1)
		{
			free(in.stored);
			exit(1);
		}
		divide_arg(&in);
		if (access(in.array[0], F_OK) == -1)
			perror(in.name_shell);
		else
		{
			chlid_pid = fork();
			if ((chlid_pid == 0) && (execve(in.array[0], in.array, NULL) == -1))
				perror(in.name_shell);
			wait(&status);
		}
		free_array(&in);
		free(in.stored);
	}
	return (0);
}

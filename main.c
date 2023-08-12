#include "main.h"

/**
 * main - Entry points.
 * Description: create a UNIX command line interpreter.
 * Return: 0 Always Success, otherwise return 1.
 */

int main(void)
{
	const char *promt = "#cisfun$ ";
	char *stored = NULL, **argv = NULL;
	int status = 0;
	ssize_t read;
	size_t len = 0;
	pid_t chlid_pid = 0;

	while (1)
	{
		write(STDOUT_FILENO, promt, strlen(promt));
		len = 0;
		read = getline(&stored, &len, stdin);
		if (read == -1)
		{
			if (argv)
				free(argv);
			free(stored);
			exit(1);
		}
		stored[read - 1] = '\0';
		/* start make array of stored an argumant */
		argv = divide_arg(argv, stored);
		if (access(argv[0], F_OK) == -1)
			perror("access");
		else
		{
			chlid_pid = fork();
			if ((chlid_pid == 0) && (execve(argv[0], argv, NULL) == -1))
				perror("execve");
			wait(&status);
		}
		free_arg(argv);
		free(stored);
	}
	return (0);
}

#include "main.h"

/**
 * main - Entry points.
 * Description: create a UNIX command line interpreter.
 * Return: 0 Always Success, otherwise return 1.
 */

int main(void)
{
	const char *promt = "#cisfun$ ";
	char *stored = NULL;
	int status = 0;
	ssize_t read;
	size_t len = 0;
	pid_t chlid_pid = 0;
	char *argv[2];

	while (1)
	{
		write(STDOUT_FILENO, promt, strlen(promt));
		len = 0;
		read = getline(&stored, &len, stdin);
		if (read == -1)
		{
			free(argv[0]);
			free(stored);
			exit(1);
		}
		stored[read - 1] = '\0';
		if (access(stored, F_OK) == -1)
			perror(stored);
		else
		{
			argv[0] = stored;
			argv[1] = NULL;
			chlid_pid = fork();
			if ((chlid_pid == 0) && (execve(stored, argv, NULL) != 0))
				perror(stored);
		}
		wait(&status);
	}
	free(stored);
	free(argv[0]);
	return (0);
}

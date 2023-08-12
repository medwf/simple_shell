#include "main.h"

/**
 * main - Entry points.
 * Description: create a UNIX command line interpreter.
 * Return: 0 Always Success, otherwise return 1.
 */

int main(void)
{
	const char *promt = "#cisfun$ ", *delim = " ";
	char *stored = NULL, **argv = NULL, *token;
	int status = 0;
	ssize_t read;
	size_t len = 0;
	int num_token, fr;
	pid_t chlid_pid = 0;

	while (1)
	{
		argv = malloc(sizeof(char *) * 2);
		argv[0] = NULL;
		argv[1] = NULL;
		write(STDOUT_FILENO, promt, strlen(promt));
		len = 0;
		read = getline(&stored, &len, stdin);
		if (read == -1)
		{
			free(argv);
			free(stored);
			exit(1);
		}
		stored[read - 1] = '\0';
		/* start make array of stored an argumant */
		num_token = 0;
		fr = 0;
		token = strtok(stored, delim);
		while (token)
		{
			argv = realloc(argv, sizeof(char *) * (num_token + 2));
			if (!argv)
			{
				while (argv[fr])
					free(argv[fr++]);
				free(argv);
				free(stored);
				perror("realloc");
				exit(1);
			}
			argv[num_token] = realloc(argv[num_token], sizeof(char) * (strlen(token) + 1));
			strcpy(argv[num_token++], token);
			token = strtok(NULL, delim);
		}
		argv[num_token] = NULL;
		if (access(argv[0], F_OK) == -1)
			perror("access");
		else
		{
			chlid_pid = fork();
			if ((chlid_pid == 0) && (execve(argv[0], argv, NULL) == -1))
				perror("execve");
			wait(&status);
		}
		fr = 0;
		while (argv[fr])
			free(argv[fr++]);
		free(argv);
		free(stored);
	}
	return (0);
}

#include "main.h"
/**
 * print - a function that print a string.
 * @str: a pointer to string.
 * Return: the number of character print.
 */
int print(const char *str)
{
	int len = _strlen(str);

	return (write(STDOUT_FILENO, str, len));
}

/**
 * _getline - a function that stored a command and delete space from beginning.
 * @ptr: a pointer to stored.
 */
void _getline(input *ptr)
{
	size_t len = 0;
	ssize_t read;

	read = getline(&ptr->stored, &len, stdin);
	if (read == -1)
	{
		free(ptr->stored);
		exit(EXIT_SUCCESS);
	}
	ptr->stored[read - 1] = '\0';
	dte_space(ptr->stored);
}
/**
 * fork_execve - a function that handle fork and execve
 * @ptr: a pointer to struct.
 */
void fork_exeve(input *ptr)
{
	pid_t ch_pid;
	int status = 0;

	ch_pid = fork();
	if ((ch_pid == 0) && (execve(ptr->array[0], ptr->array, NULL) == -1))
	{
		perror(ptr->name_shell);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}
/**
 * init_struct - initialization of structures.
 * @p: a pointer to structures.
 */
void init_struct(input *p, const char *name)
{
	p->stored = NULL;
	p->array = NULL;
	p->name_shell = name;
}

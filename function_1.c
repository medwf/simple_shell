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
void fork_execve(input *ptr, size_t count)
{
	pid_t ch_pid;
	int status = 0;

	ch_pid = fork();
	if ((ch_pid == 0) && (execve(ptr->array[0], ptr->array, NULL) == -1))
	{
		print_error(ptr, count, "Permission denied\n");
		exit(EXIT_FAILURE);
	}
	wait(&status);
}
/**
 * init_struct - initialization of structures.
 * @p: a pointer to structures.
 * @name: a pointer to string argv[0].
 */
void init_struct(input *p, const char *name)
{
	p->stored = NULL;
	p->array = NULL;
	p->name_shell = name;
}

/**
 *_getenv : get the value for any environment variable
 *@name : the name of environment variable
 *@env : environment variable
 */
char *_getenv(char *name, char **env)
{
	int i = 0;
	size_t ptr;

	if (name == NULL || env == NULL)
		return (NULL);

	ptr = _strlen(name);
	while (env[i])
	{
		if (_strncmp(env[i], name, ptr) == 0 && env[i][ptr] == '=')
			return (env[i] + ptr + 1);
		i++;
	}
	return (NULL);
}

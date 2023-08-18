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
		exit(ptr->_exit);
	}
	ptr->stored[read - 1] = '\0';
	dte_space(ptr->stored);
}
/**
 * fork_execve - a function that handle fork and execve
 * @ptr: a pointer to struct.
 * @count: the number of execute command.
 */
void fork_execve(input *ptr, size_t count)
{
	pid_t ch_pid, pr_pid;
	int status = 0;

	ch_pid = fork();
	if ((ch_pid == 0) && (execve(ptr->array[0], ptr->array, NULL) == -1))
	{
		print_error(ptr, count, "execve\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		pr_pid = waitpid(ch_pid, &status, 0);
		if (pr_pid == -1)
		{
			print_error(ptr, count, "waitpid\n");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status))
			ptr->_exit = WEXITSTATUS(status);
	}
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
	p->_exit = 0;
}

/**
 * _getenv - get the value for any environment variable
 * @name : the name of environment variable
 * @env : environment variable
 * Return: return an string of full path.
 */
char *_getenv(char *name, char **env)
{
	int i = 0;
	size_t len;

	if (name == NULL || env == NULL)
		return (NULL);

	len = _strlen(name);
	while (env[i])
	{
		if (_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}

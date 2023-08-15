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

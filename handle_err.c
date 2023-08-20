#include "main.h"

/**
 * print_error - a function that print error msg to
 *                      STDERR with counting for wich process.
 * @ptr: a pointer to structure.
 * @err: a pointer to string mdg err.
 */
void print_error(shell *ptr, char *err)
{
	write(STDERR_FILENO, ptr->name_shell, _strlen(ptr->name_shell));
	write(STDERR_FILENO, ": ", 2);
	print_number(ptr->count);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ptr->array[0], _strlen(ptr->array[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, err, _strlen(err));
}
/**
 * print_number - prints an Unsigned integer number in stderr;
 * @n: integer to be printed;
 */
void print_number(size_t n)
{
	if (!(n / 10))
	{
		putchar_err(n + '0');
		return;
	}
	if (n / 10)
		print_number(n / 10);

	putchar_err((n % 10) + '0');
}
/**
 * putchar_err - a function that change number to char and print it stderr
 * @c: character.
 */
void putchar_err(char c)
{
	write(STDERR_FILENO, &c, 1);
}

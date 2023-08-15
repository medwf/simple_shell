#include "main.h"
/**
 *_strcpy - copies the string pointed to by src to dest.
 *@src: pointer to string.
 *@dest: string coped.
 *Return: return value.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0 ; *(src + i) != '\0' ; i++)
	{
		*(dest + i) = *(src + i);
	}
	*(dest + i) = '\0';
	return (dest);
}

/**
 * _strlen - returns the length of a string.
 *@s: pointers to string.
 * Return: to value of long string.
 */
int _strlen(const char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
		i++;
	return (i);
}

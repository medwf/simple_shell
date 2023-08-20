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

	for (i = 0; *(src + i) != '\0'; i++)
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

	if (s == NULL)
		return (0);
	while (*(s + i) != '\0')
		i++;
	return (i);
}

/**
 * _strdup - a function that returns a pointer
 *            to a newly allocated space in memory,
 *              which contains a copy of the string given as a parameter
 * @str: Pointer to string.
 * Return: On success (str), otherwase (NULL).
 */

char *_strdup(char *str)
{
	int i = 0;
	char *dup;

	if (str == NULL)
		return (NULL);

	dup = malloc((1 + _strlen(str)) * sizeof(char));

	if (dup == NULL)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/**
 * _strcat - function that concatenates
 *          two strings.
 *
 * @dest: pointer to destnation input
 * @src: pointer to source input
 *
 * Return: pointer to resulting string @dest
 */
char *_strcat(char *dest, char *src)
{
	int c, c2;

	c = 0;
	/*find the size of dest array*/
	while (dest[c])
		c++;

	for (c2 = 0; src[c2]; c2++)
		dest[c++] = src[c2];
	dest[c] = '\0';
	return (dest);
}
/**
 * _strncmp - a function that compares the n number of fist strings
 *                             with second string.
 * @s1: string 1 input to compare
 * @s2: against this other string 2
 * @n: the number of byte want to compare.
 * Return: 0 if s1 and s2 are equal
 *        negative integer if the stopping character
 *                in @s1 was less than the stopping
 *                character in @s2
 *        positive integer if the stopping character
 *                in @s1 was greater than the stopping
 *                character in @s2
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i = 0, r;

	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			r = s1[i] - s2[i];
			break;
		}
		else
			r = s1[i] - s2[i];
		i++;
	}
	return (r);
}

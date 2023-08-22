#include "main.h"

/**
 * _strcmp - a function that compares two strings
 *
 * @s1: string 1 input to compare
 * @s2: against this other string 2
 *
 * Return: 0 if s1 and s2 are equal
 *        negative integer if the stopping character
 *                in @s1 was less than the stopping
 *                character in @s2
 *        positive integer if the stopping character
 *                in @s1 was greater than the stopping
 *                character in @s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, r;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			r = s1[i] - s2[i];
			break;
		}
		else
		{
			r = s1[i] - s2[i];
		}
		i++;
	}

	return (r);
}
/**
 *_atoi - a function that change string to integer number
 *@str: a ppinter to string.
 *Return: integer number or -1 if iy failed.
 */
int _atoi(char *str)
{
	int i = 0, ret_int_num = 0, helps = 0;

	while (*(str + i))
	{
		/* check it char is not a number to return -1 in failed.*/
		if (*(str + i) < '0' || *(str + i) > '9')
			return (-1);
		/* if it's number than change it fron char to integer*/
		helps = *(str + i) - '0';
		ret_int_num = ret_int_num * 10 + helps;
		helps = 0;
		i++;
	}
	return (ret_int_num);
}

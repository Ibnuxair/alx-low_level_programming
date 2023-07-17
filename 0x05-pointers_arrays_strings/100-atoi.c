#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: string
 *
 * Return: integer number
 */

int _atoi(char *s)
{
	int res = 0;
	int sign = 1;
	int is_digit = 0;

	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
		{
			is_digit = 1;
			res = res * 10 + (*s - '0');
		}
		else if (is_digit)
		{
			break;
		}
		else if (*s == '-')
		{
			sign *= -1;
		}
		s++;
	}

	return res * sign;
}

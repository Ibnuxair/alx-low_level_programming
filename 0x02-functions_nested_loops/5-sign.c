#include "main.h"

/**
 * print_sign -  prints the sign of a number
 * @n: holds the number
 *
 * Return: returns 1, 0 0r -1 and prints their signs
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}

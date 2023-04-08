#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the integer input
 *
 * Return: nothing
 */

void print_binary(unsigned long int n)
{
	int i;
	int count;
	unsigned long int bit;

	count = 0;

	for (i = 63; i >= 0; i--)
	{
		bit = (n >> i) & 1;
		if (bit)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');

		if (!count)
			_putchar('o');
	}
}

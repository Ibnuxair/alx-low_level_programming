#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip to get
 * from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: the number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i;
	int count = 0;
	unsigned long int currt;
	unsigned long int xorResult = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		currt = xorResult >> i;
		if (currt & 1)
			count++;
	}
	return (count);
}

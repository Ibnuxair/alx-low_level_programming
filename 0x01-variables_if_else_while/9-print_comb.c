#include <stdio.h>

/**
 * main -  prints numbers from 0 t0 9
 * ch - hold the firt number
 *
 * Return: 0 to terminate the program
 */

int main(void)
{
	int i = 0;

	while (i < 10)
	{
		putchar(i + '0');
		if (i < 9)
		{
			putchar(',');
			putchar(' ');
		}
		i++;
	}
	putchar('\n');
	return (0);
}

#include <stdio.h>
/**
 * main -  prints hexadecimal numbers
 *
 * Return: 0 to terminate the program
*/
int main(void)
{
	int i = 0;
	int j = 0;

	while (i <= 9)
	{
		putchar('0' + i);
		i++;
	}

	while (j <= 5)
	{
		putchar('a' + j);
		j++;
	}
	putchar('\n');
	return (0);
}

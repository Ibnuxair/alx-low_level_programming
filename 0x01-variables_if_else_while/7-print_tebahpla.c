#include <stdio.h>
/**
 * main -  prints alphabets in reverse order
 * ch - hold the firt number
 *
 * Return: 0 to terminate the program
 */

int main(void)
{
	char ch = 'z';

	while (ch >= 'a')
	{
		putchar(ch);
		ch--;
	}
	putchar('\n');
	return (0);
}

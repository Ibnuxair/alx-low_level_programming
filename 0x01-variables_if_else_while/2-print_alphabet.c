#include <stdio.h>

/**
 * main - prints prints the alphabet in lowercase
 * ch - hold the firt characte
 *
 * Return: 0 to terminate the program
 */

int main(void)
{
	char ch = 'a';

	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');

	return (0);
}

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
	char ch1 = 'A';

	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}

	while (ch1 <= 'Z')
	{
		putchar(ch1);
		ch1++;
	}
	putchar('\n');

	return (0);
}

#include <stdio.h>
/**
 * main -  prints the alphabet in lowercase except q and e
 * ch - hold the firt characte
 *
 * Return: 0 to terminate the program
 */

int main(void)
{
	char ch = 'a';

	while (ch <= 'z')
	{
		if (ch == 'q' || ch == 'e')
		{
			ch++;
			continue;
		}
		putchar(ch);
		ch++;
	}
	putchar('\n');
	return (0);
}

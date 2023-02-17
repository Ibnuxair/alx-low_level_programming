#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - prints whether the random number generated is +, 0, or -
 * n - holds the number
 * 
 * Return: 0 to terminate the program
 */

int main(void)
{
int n;

srand(time(0));
n = rand() - RAND_MAX / 2;
if (n > 0)
{
	printf("%d", n);
	printf(" is positive\n");
}
else if (n == 0)
{
	printf("%d", n);
	printf(" is zero\n");
}
else
{
	printf("%d", n);
	printf(" is negative\n");
}

return (0);
}

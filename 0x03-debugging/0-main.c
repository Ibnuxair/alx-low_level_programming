#include "main.h"

/**
 * positive_or_negative - prints whether number is +ve or -ve
 * @n: holds the number
 */

void positive_or_negative(int n)
{
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

}

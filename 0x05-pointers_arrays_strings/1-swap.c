#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a: is the first pointer
 * @b: second pointer
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

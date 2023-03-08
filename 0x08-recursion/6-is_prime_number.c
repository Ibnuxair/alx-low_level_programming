#include "main.h"

int check_prime(int n, int i);

/**
 * is_prime_number -checks if a number is prime or not
 * @n: the number
 *
 * Return: returns 1 if the input integer is a prime number, otherwise return 0
 */

int is_prime_number(int n)
{
	return (check_prime(n, 1));
}

/**
 * check_prime - checks if number is prime
 * @n: number to be checked
 * @i: iterate number
 *
 *Return: returns 1 for prime, 0 for composite
 */

int check_prime(int n, int i)
{
	if (n <= 1)
		return (0);
	if (n % i == 0 && i > 1)
		return (0);
	if ((n / i) < i)
		return (1);
	return (check_prime(n, i + 1));
}

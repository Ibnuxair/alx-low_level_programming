#include "main.h"

/**
 * *_memset - fills memory with a constant byte
 * @s: pointer to the memory area
 * @b: constant byte
 * @n: bytes of the memory area
 *
 *Return: Returns a pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}

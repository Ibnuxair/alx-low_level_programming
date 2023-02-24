#include "main.h"

/**
 * _isupper -  checks for uppercase character
 * @c: holds the character
 *
 * Return: returns 1 if c is uppercase otherwise returns 0
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

#include "main.h"

/**
 * _islower -  checks for lowercase character
 * @c: receives the input
 *
 * Return: returns 1 if the char is lowercase else returns 0
 */

int _islower(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	else
		return (0);
}

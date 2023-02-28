#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: is the pointer
 *
 * Return: returns the length of the string
 */

int _strlen(char *s)
{
	int count = 0;
	char *ch = s;

	while (*ch != '\0')
	{
		count = count + 1;
		ch++;
	}
	return (count);
}

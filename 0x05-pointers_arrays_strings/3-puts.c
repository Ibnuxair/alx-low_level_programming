#include "main.h"
#include <string.h>

/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: is the pointer
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}

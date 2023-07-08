#include "main.h"

/**
 * _putchar - prints the character c to the stdout
 * @c: holds the character
 *
 *Return:  returns 0
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

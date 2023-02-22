#include "main.h"
#include <unistd.h>

/* 
 * _putchar - prints the character c to the stdout
 * c - holds the character
 *
 *Return:  returns 0
 */

int _putchar(int c)
{
        return (write(1, &c, 1));
}

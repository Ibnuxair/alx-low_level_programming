#include <stdio.h>
/**
 * main -  prints numbers from 0 t0 9
 * ch - hold the firt number
 *
 * Return: 0 to terminate the program
 */

int main(void)
{
        int i = 0x0;

        while (i <= 0xf)
        {	
                putchar(i);
                i++;
        }
        putchar('\n');
        return (0);
}

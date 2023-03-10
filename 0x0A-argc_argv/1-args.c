#include "main.h"

/**
 * main - prints the number of arguments passed into it
 * @argc: lenth of the arguments
 * @argv: array of the arguments
 *
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	(void)argv;
	
	printf("%d\n", argc - 1);

	return (0);
}

#include "main.h"

/**
 * main -  print the result of the multiplication, followed by a new line
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (always success) or 1 (when there is an error)
 */

int main(int argc, char *argv[])
{
	int mult;

	if (argc > 1)
	{
		mult = atoi(argv[1]) * atoi(argv[2]);
		printf("%d\n", mult);
		return (0);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
}

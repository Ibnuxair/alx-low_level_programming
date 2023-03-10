#include "main.h"

/**
 * main - prints the name of the program
 * @argc: lenth of the arguments
 * @argv: array of the arguments
 *
 * Return: always 0
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}

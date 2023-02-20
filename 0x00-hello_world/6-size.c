#include<stdio.h>

/**
 * main - prints exacty the size of datatype
 * charType: hold the size of char
 * intType: hold the size of intType
 * longIntType: hold the size of longInt
 * longLongIntType: hold the size of longLongInt
 *
 * Return: 0 to terminate the program
 */

int main(void)
{
	char charType;
	int intType;
	long int longIntType;
	long long int longLongIntType;
	float floatType;

	printf("Size of a char: %lu byte(s)\n", sizeof(charType));
	printf("Size of an int: %lu byte(s)\n", sizeof(intType));
	printf("Size of a long int: %lu byte(s)\n", sizeof(longIntType));
	printf("Size of a long long int: %lu byte(s)\n", sizeof(longLongIntType));
	printf("Size of a float: %lu byte(s)\n", sizeof(floatType));

	return (0);

}

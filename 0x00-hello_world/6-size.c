#include<stdio.h>

/**
 * main - prints exacty the size of datatype
 * @charType: hold the size of char
 * @intType: hold the size of intType
 * @longIntType: hold the size of longInt
 * @longLongIntType: hold the size of longLongInt
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

printf("Size of a char: %zu bytes\n", sizeof(charType));
printf("Size of a int: %zu bytes\n", sizeof(intType));
printf("Size of a long int: %zu bytes\n", sizeof(longIntType));
printf("Size of a long long int: %zu byte\n", sizeof(longLongIntType));
printf("Size of a float: %zu bytes\n", sizeof(floatType));

return (0);

}

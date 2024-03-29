 #include "main.h"

/**
 * *array_range - creates an array of integers
 * @min: minimum input
 * @max: maximum input
 *
 * Return: a pointer to the newly created array
 */

int *array_range(int min, int max)
{
	int i = 0;
	int *a;

	if (min > max)
		return (NULL);

	a = malloc((sizeof(int) * (max - min)) + sizeof(int));

	if (a == NULL)
		return (NULL);

	while (min <= max)
	{
		a[i] = min;
		i++;
		min++;
	}
	return (a);
}

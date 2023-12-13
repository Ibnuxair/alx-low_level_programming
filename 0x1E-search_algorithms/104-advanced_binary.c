#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index where value is located or -1 if not present
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, mid;
	int found;

	if (!array || size == 0)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size - 1; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	mid = (size - 1) / 2;

	if (array[mid] == value)
	{
		if (mid == 0 || array[mid - 1] < value)
			return (mid);
	}

	if (array[mid] < value)
	{
		found = advanced_binary(array + mid + 1, size - mid - 1, value);
		return (found != -1 ? (int)(mid + 1 + found) : -1);
	}
	else
	{
		return (advanced_binary(array, mid + 1, value));
	}
}

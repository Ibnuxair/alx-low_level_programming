#include "search_algos.h"

/**
 * bin_search - Searches for a value in a sorted array using Binary Search
 * @array: Pointer to the first element of the array
 * @value: Value to search for
 * @left: The left index
 * @right: The right index
 *
 * Return: Index of the value if found, otherwise -1
 */
int bin_search(int *array, int value, size_t left, size_t right)
{
	size_t l = left, r = right - 1, mid, i;

	if (array == NULL)
		return (-1);

	while (l <= r)
	{
		printf("Searching in array: ");
		for (i = l; i < r; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		mid = (l + r) / 2;

		if (array[mid] < value)
			l = mid + 1;
		else if (array[mid] > value)
			r = mid - 1;
		else
			return (mid);
	}

	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array using
 *                      Exponential Search algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value if found, otherwise -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, left, right;

	if (array == NULL || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       bound, array[bound]);
		bound *= 2;
	}

	left = bound / 2;
	right = (bound < size) ? bound + 1 : size;

	printf("Value found between indexes [%lu] and [%lu]\n",
	       left, right - 1);
	return (bin_search(array, value, left, right));
}

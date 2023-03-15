#include "main.h"

/**
 * **alloc_grid -  returns a pointer to a 2 dimensional array of integers
 * @width: width input
 * @height: height input
 *
 * Return: a pointer to a 2 dimensional array
 */

int **alloc_grid(int width, int height)
{
	int **ptr2arr;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	ptr2arr = malloc(height * sizeof(int));

	if (ptr2arr == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		ptr2arr[i] = malloc(sizeof(int) * width);
		if (ptr2arr[i] == NULL)
		{
			for (; i >= 0; i--)
				free(ptr2arr[i]);
			free(ptr2arr);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			ptr2arr[i][j] = 0;
	}
	return (ptr2arr);
}

#include "main.h"

/**
 * *_calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: number of byte
 *Return: nothing
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	int i, l;
	char *ptr;

	if  (nmemb == 0 || size == 0)
		return (NULL);

	l = nmemb * size;
	ptr = malloc(l);

	if (ptr == NULL)
		return (NULL);

	i = 0;
	while (i < l)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

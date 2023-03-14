#include "main.h"

/**
 * *_strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the string
 *
 * Return: returns a pointer to a newly allocated space or NULL if str = NULL
 */

char *_strdup(char *str)
{
	char *dist;
	int i, j;

	if (str == NULL)
		return (NULL);

	i = 0;
	while (str[i] != '\0')
		i++;

	dist = malloc((i + 1) * sizeof(char));

	if (dist == NULL)
		return (NULL);

	for (j = 0; str[j]; j++)
		dist[j] = str[j];

	return (dist);
}

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
	char *dist = malloc(strlen(str) + 1);

	if (str == NULL)
		return (NULL);

	strcpy(dist, str);
	return (dist);
}

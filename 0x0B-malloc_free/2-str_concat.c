#include "main.h"

/**
 * *str_concat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: returns a pointer to s1 or NULL on failure
 */

char *str_concat(char *s1, char *s2)
{
	char *ptr;
	int i, j;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	i = 0;
	while (s1[i] != '\0')
		i++;

	j = 0;
	while (s2[j] != '\0')
		j++;

	ptr = malloc((i + j + 1) * sizeof(char));

	if (ptr == NULL)
		return (NULL);

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}

	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';

	return (ptr);
}

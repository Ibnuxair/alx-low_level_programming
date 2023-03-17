#include "main.h"

/**
 * string_nconcat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes
 *
 * Return: rturns a pointer to a newly allocated space in memory,
 * which contains s1, followed by the first n bytes of s2, and null terminated
 * returns NULL if the the function fails
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0, j = 0, k = 0, l = 0;
	char *conc;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[i])
		i++;

	while (s2[k])
		k++;

	if (n >= k)
		l = i + k;
	else
		l = i + n;

	conc = malloc(sizeof(char) * l + 1);

	if (conc == NULL)
		return (NULL);

	k = 0;
	while (j < l)
	{
		if (j <= i)
			conc[j] = s1[j];
		if (j >= i)
		{
			conc[j] = s2[k];
			k++;
		}
		j++;
	}
	conc[j] = '\0';
	return (conc);
}

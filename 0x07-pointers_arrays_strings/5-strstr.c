#include "main.h"

/**
 * *_strstr -  locates a substring
 * @haystack: string
 * @needle: substring
 *
 * Return: Returns a pointer to the beginning of the located substring,
 * or NULL if the substring is not found
 */

char *_strstr(char *haystack, char *needle)
{
	int i;

	while (*haystack)
	{
		for (i = 0; needle[i]; i++)
		{
			if (*haystack == needle[i])
				return (needle);
		}
		haystack++;
	}
	return ('\0');
}

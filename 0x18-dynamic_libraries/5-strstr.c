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
	size_t i;

	if (*needle == '\0')
	{
		return (haystack);
	}

	for (i = 0; i < strlen(haystack); i++)
	{
		if (*(haystack + i) == *needle)
		{
			char *ptr = strstr(haystack + i + 1, needle + 1);

			return ((ptr) ? ptr - 1 : NULL);
		}
	}

	return (NULL);
}

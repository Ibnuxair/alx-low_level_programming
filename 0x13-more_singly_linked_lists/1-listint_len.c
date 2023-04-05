#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t list
 * @h: header pointer
 *
 * Return: the number
 */

size_t listint_len(const listint_t *h)
{
	size_t nofEle = 0;

	while (h)
	{
		nofEle++;
		h = h->next;
	}

	return (nofEle);
}

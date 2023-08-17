#include "lists.h"

/**
 *  dlistint_len - returns the number of elements in a list
 * @h: the head pointer
 *
 * Return: the number of nodes
 */

size_t dlistint_len(const dlistint_t *h)
{
	int count = 0;
	const dlistint_t *tmp = h;

	if (h == NULL)
		return (0);

	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

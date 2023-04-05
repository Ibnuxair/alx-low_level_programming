#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: header pointer
 *
 * Return: the number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t nNodes = 0;

	if (h == NULL)
		printf("nill\n");

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		nNodes++;
	}
	return (nNodes);
}

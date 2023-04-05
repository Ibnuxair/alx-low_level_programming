#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: header pointer
 *
 * Return: the number of nodes
 */

size_t print_listint(const listint_t *h)
{
	const listint_t *temp = h;
	size_t nNodes = 0;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		nNodes++;
	}
	return (nNodes);
}

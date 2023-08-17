#include "lists.h"

/**
 * print_dlistint - prints all the elements of a list
 * @h: the head pointer
 *
 * Return: the number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	int count = 0;
	const dlistint_t *tmp = h;

	if (h == NULL)
		return (0);

	while (tmp)
	{
		printf("%d\n", tmp->n);
		count++;
		tmp = tmp->next;
	}
	return (count);
}

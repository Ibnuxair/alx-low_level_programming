#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: the pointer
 * @index: node index
 *
 * Return: nth node, NULL if the node does not exist
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;
	dlistint_t *curr;

	curr = head;
	while (curr)
	{
		if (count == index)
			return (curr);
		count++;
		curr = curr->next;
	}
	return (NULL);
}

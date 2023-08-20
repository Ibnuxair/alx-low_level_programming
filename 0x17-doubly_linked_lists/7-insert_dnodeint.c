#include "lists.h"
/**
 * dlist_len - returns the length of the list
 * @h: the head pointer
 *
 * Return: the length
 */
unsigned int dlist_len(dlistint_t *h)
{
	dlistint_t *curr = h;
	unsigned int count = 0;

	while (curr != NULL)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}
/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: the head double pointer
 * @idx: the position to insert the node
 * @n: data to be stored in the newly created node
 *
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *curr, *new_node;
	unsigned int len = dlist_len(*h);
	unsigned int i = 1;

	if (idx > len)
		return (NULL);

	/* Handle cases of adding at the beginning or end */
	if (idx == 0)
		return (add_dnodeint(h, n));
	if (idx == len)
		return (add_dnodeint_end(h, n));

	curr = *h;
	/* Traverse to the node before the desired index */
	while (i < idx)
	{
		curr = curr->next;
		i++;
	}

	/* Create the new node and update its pointers */
	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = curr;
	new_node->next = curr->next;
	curr->next = new_node;
	new_node->next->prev = new_node;

	return (new_node);
}

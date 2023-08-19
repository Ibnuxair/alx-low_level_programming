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
	dlistint_t *curr, *new_node, *prev_node;
	unsigned int len = dlist_len(*h);
	unsigned int i;

	if (idx > len)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));
	if (idx == len)
		return (add_dnodeint_end(h, n));

	curr = *h;
	prev_node = NULL;

	/* Traverse to the node before the desired index */
	for (i = 0; i < idx && curr != NULL; i++)
	{
		prev_node = curr;
		curr = curr->next;
	}

	if (i != idx)
		return (NULL); /* Index out of bounds */

	/* Create the new node and update its pointers */
	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = prev_node;
	new_node->next = curr;

	if (prev_node != NULL)
		prev_node->next = new_node;

	if (curr != NULL)
		curr->prev = new_node;

	return (new_node);
}

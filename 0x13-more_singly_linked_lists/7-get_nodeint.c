#include "lists.h"

/**
 * *get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to the first element
 * @index: where index is the index of the node, starting at 0
 *
 * Return: node and if the node does not exist, return NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *temp = head;
	unsigned int i = 0;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	return (temp ? temp : NULL);
}

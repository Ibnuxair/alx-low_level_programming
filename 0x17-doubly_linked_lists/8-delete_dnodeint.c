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
 * delete_dnodeint_at_index - deletes the node at a given index
 * @head: the head double pointer
 * @index: the index of the node to be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *curr, *tobe_del, *next;
	unsigned int i, len = dlist_len(*head);

	if (index >= len)
		return (-1);

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		tobe_del = *head;
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(tobe_del);
		return (1);
	}

	curr = *head;
	i = 1;
	while (i < index)
	{
		curr = curr->next;
		i++;
	}

	if (curr == NULL)
		return (-1);

	tobe_del = curr->next;
	if (tobe_del->next != NULL)
	{
		next = tobe_del->next;
		next->prev = curr;
		curr->next = next;
	}
	free(tobe_del);

	return (1);
}

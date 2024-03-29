#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: header pointer
 *
 * Return: returns the head node’s data (n).
 *         if the linked list is empty return 0
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (!head || !*head)
		return (0);

	temp = (*head)->next;
	n = (*head)->n;
	free(*head);
	*head = temp;

	return (n);
}

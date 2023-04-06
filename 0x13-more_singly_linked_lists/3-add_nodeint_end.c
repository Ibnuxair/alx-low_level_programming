#include "lists.h"

/**
 * *add_nodeint_end -  adds a new node at the end of a listint_t list
 * @head: pointer to the head pointer
 * @n: interger input
 *
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newNode;

	newNode = malloc(sizeof(listint_t));
	if (!newNode)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
		return (newNode);
	}

	while ((*head)->next)
		*head = (*head)->next;

	(*head)->next = newNode;

	return (newNode);
}

#include "lists.h"

/**
 * sum_dlistint - sum of all the data (n) of a dlistint_t linked list
 * @head: the pointer
 *
 * Return:  returns the sum of all the data (n)
 */

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *curr;
	int sum = 0;

	curr = head;
	while (curr)
	{
		sum += curr->n;
		curr = curr->next;
	}
	return (sum);
}

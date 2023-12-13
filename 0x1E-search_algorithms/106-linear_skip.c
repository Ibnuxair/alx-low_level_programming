#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in.
 * @value: Value to search for.
 *
 * Return: Pointer to the 1st node where value is located, or NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express = list, *node = NULL;

	if (!list)
		return (NULL);
	while (express)
	{
		node = express;
		if (!express->express || express->express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
			       express->index, express->express ?
			       express->express->index : 0);
			printf("Value checked at index [%lu] = [%d]\n",
			       express->index, express->n);
			break;
		}
		printf("Value checked at index [%lu] = [%d]\n",
		       express->index, express->n);
		express = express->express;
	}
	if (express->express)
	{
		while (list && list->index < express->express->index)
		{
			printf("Value checked at index [%lu] = [%d]\n",
			       list->index, list->n);
			if (list->n == value)
				return (list);
			list = list->next;
		}
	}
	else
	{
		while (node->next)
		{
			printf("Value checked at index [%lu] = [%d]\n",
			       node->index, node->n);
			if (node->n == value)
				return (node);
			node = node->next;
		}
	}
	return (NULL);
}

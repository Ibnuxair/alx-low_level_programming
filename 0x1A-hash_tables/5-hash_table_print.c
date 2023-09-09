#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: the hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *curr_node;
	unsigned long int i, first = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		curr_node = ht->array[i];
		while (curr_node)
		{
			if (!first)
				printf(",");
			printf("'%s': '%s'", curr_node->key, curr_node->value);
			first = 0;
			curr_node = curr_node->next;
		}
	}
	 printf("}\n");
}

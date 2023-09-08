#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the table.
 *
 * Return: A pointer to the newly created hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;
	unsigned long int i;

	hash_table = malloc(sizeof(hash_table_t));
	if (!hash_table)
		return (NULL);

	hash_table->array = malloc(sizeof(hash_node_t *) * size);
	if (!hash_table->array)
		return (NULL);

	hash_table->size = size;
	for (i = 0; i < hash_table->size; i++)
		hash_table->array[i] = NULL;

	return (hash_table);
}

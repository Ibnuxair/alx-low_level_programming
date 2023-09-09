#include "hash_tables.h"

/**
 * create_node - creates a node
 * @key: the key and cannot be an empty string
 * @value: the value associated with the key
 *
 * Return: a pointer to the new created node, or NULL on failure
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (NULL);

	new_node->key = malloc(strlen(key) + 1);
	if (!new_node->key)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = malloc(strlen(value) + 1);
	if (!new_node->value)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;

	return (new_node);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table
 *  @key: the key and cannot be an empty string
 * @value: the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *curr_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	curr_node = ht->array[index];
	if (curr_node == NULL)
	{
		ht->array[index] = new_node;
	}
	else
	{
		new_node->next = curr_node;
		curr_node = new_node;
	}
	return (1);
}

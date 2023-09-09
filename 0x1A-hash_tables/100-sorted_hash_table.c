#include "hash_tables.h"

/**
 * shash_table_create - Creates a hash table.
 * @size: The size of the table.
 *
 * Return: Newly created hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *shash_table;
        unsigned long int i;

        shash_table = malloc(sizeof(shash_table_t));
        if (!shash_table)
                return (NULL);

        shash_table->array = malloc(sizeof(shash_node_t *) * size);
        if (!shash_table->array)
                return (NULL);

	shash_table->shead = NULL;
	shash_table->stail = NULL;

	shash_table->size = size;
        for (i = 0; i < shash_table->size; i++)
                shash_table->array[i] = NULL;

        return (shash_table);
}

/**
 * shash_table_set - Adds an element to the sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key (cannot be an empty string).
 * @value: The value associated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *curr, *prev;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	curr = ht->array[index];
	while (curr != NULL)
	{
		if (strcmp(curr->key, key) == 0)
		{
			free(curr->value);
			curr->value = strdup(value);
			return (1);
		}
		curr = curr->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	/* Update sorted linked list */
	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else
	{
		prev = NULL;
		curr = ht->shead;
		while (curr && strcmp(curr->key, key) < 0)
		{
			prev = curr;
			curr = curr->snext;
		}
		if (prev)
			prev->snext = new_node;
		else
			ht->shead = new_node;

		if (curr)
			curr->sprev = new_node;
		else
			ht->stail = new_node;

		new_node->sprev = prev;
		new_node->snext = curr;
	}

	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: The sorted hash table.
 * @key: The key you are looking for.
 *
 * Return: The value associated with the element, or NULL if key
 *         couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *curr;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	curr = ht->array[index];
	while (curr != NULL)
	{
		if (strcmp(curr->key, key) == 0)
			return (curr->value);
		curr = curr->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *curr;

	if (ht == NULL)
		return;

	printf("{");
	curr = ht->shead;
	while (curr != NULL)
	{
		printf("'%s': '%s'", curr->key, curr->value);
		if (curr->snext != NULL)
			printf(", ");
		curr = curr->snext;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table to be deleted
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *curr, *temp;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		curr = ht->array[i];
		while (curr)
		{
			temp = curr;
			curr = curr->next;
			free(temp->key);
			free(temp->value);
			free(temp);
		}
	}
	free(ht->array);
	free(ht);
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order
 * @ht: The sorted hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *curr;

	if (ht == NULL)
		return;

	printf("{");
	curr = ht->stail;
	while (curr != NULL)
	{
		printf("'%s': '%s'", curr->key, curr->value);
		if (curr->sprev != NULL)
			printf(", ");
		curr = curr->sprev;
	}
	printf("}\n");
}

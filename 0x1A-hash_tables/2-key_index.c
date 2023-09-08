#include "hash_tables.h"

/**
 * key_index - gives  the index of a key
 * @key: the key used to generate hash value
 * @size: the size of the array of the hash table
 *
 * Return: hash value
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash, index;
	int c;

	hash = 5381; /* large prime */
	while ((c = *key++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}

	index = hash % size;

	return (index);
}

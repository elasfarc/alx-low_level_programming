#include "hash_tables.h"

/**
 * key_index - Generates an index for a given key in
 * a hash table.
 * @key: The key for which to generate the index.
 * @size: The size of the hash table.
 *
 * Return: The index for the key in the hash table.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}

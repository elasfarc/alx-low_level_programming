#include "hash_tables.h"

/**
 * hash_table_get - Retrieve the value associated with a key from a hash table
 * @ht: Pointer to the hash table
 * @key: The key to search for in the hash table
 *
 * Return:
 * If the key is found, it returns a pointer to the associated value.
 * If the key is not found or if the input parameters are invalid,
 * it returns NULL.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int hash_code;
	hash_node_t **head, *current;

	if (!ht || !ht->array)
		return (NULL);

	hash_code = key_index((unsigned char *)key, ht->size);
	head = &(ht->array[hash_code]);
	current = *(head);
	for (; current; current = current->next)
		if (strcmp(current->key, key) == 0)
			return (current->value);
	return (NULL);
}

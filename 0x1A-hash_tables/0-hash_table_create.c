#include "hash_tables.h"

/**
 * hash_table_create - Create a hash table
 * @size: The size of the hash table
 *
 * Return: A pointer to the newly created hash table, or NULL if it fails
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;
	hash_node_t **hash_arr;
	unsigned int i;

	hash_table = malloc(sizeof(hash_table_t));
	if (hash_table == NULL)
		return (NULL);

	hash_arr = malloc(sizeof(hash_node_t *) * size);
	if (hash_arr == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		hash_arr[i] = NULL;

	hash_table->size = size;
	hash_table->array = hash_arr;

	return (hash_table);
}

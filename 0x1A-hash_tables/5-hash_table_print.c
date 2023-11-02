#include "hash_tables.h"

/**
 * hash_table_print - Print the contents of a hash table
 * @ht: Pointer to the hash table
 *
 * Description:
 * This function prints the contents of a hash table in the following format:
 * {index
 *  'key': 'value', index 'key': 'value', ...
 * }
 *
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i, atleast_one_printed = 0;
	hash_node_t *node;

	if (!ht)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			printf("%s'%s': '%s'",
				atleast_one_printed ? ", " : "",
				node->key, node->value
			);
			node = node->next;
			atleast_one_printed = 1;
		}
	}
	printf("}\n");
}

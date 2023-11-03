#include "hash_tables.h"

void safe_free(void *v);
void free_hash_table_node(hash_node_t **head);

/**
 * hash_table_delete - Delete a hash table and its elements
 * @ht: Pointer to the hash table to be deleted
 *
 * Description:
 * This function deletes a hash table and its associated elements.
 * It iterates through the hash table's array and calls the
 * `free_hash_table_node` function to free all the nodes in the hash table.
 * Afterward, it frees the hash table array itself
 * and then the hash table structure.
 *
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		free_hash_table_node(&node);
	}
	safe_free(ht->array);
	safe_free(ht);
}

/**
 * free_hash_table_node - Free a linked list of hash nodes
 * @head: Pointer to the head of the linked list
 *
 * Description:
 * This function frees a linked list of hash nodes, including
 * the keys, values, and nodes themselves.
 * It iterates through the linked list, deallocating the
 * memory for each node and its associated data.
 *
 */
void free_hash_table_node(hash_node_t **head)
{
	hash_node_t *node;

	while (*head)
	{
		node = *head;
		*head = (*head)->next;
		safe_free(node->key);
		safe_free(node->value);
		safe_free(node);
	}
	head = NULL;
}

/**
 * safe_free - Safely free memory allocated for a pointer
 * @v: Pointer to the memory to be freed
 *
 * Description:
 * This function frees the memory pointed to by the given pointer `v` safely.
 * It checks if the pointer is not NULL before freeing the memory and then sets
 * the pointer to NULL after freeing the memory.
 *
 * Return: None
 */
void safe_free(void *v)
{
	if (v)
	{
		free(v);
		v = NULL;
	}
}

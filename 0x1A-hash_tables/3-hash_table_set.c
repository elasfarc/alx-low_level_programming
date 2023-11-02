#include "hash_tables.h"

hash_node_t *create_hash_node(const char *key, const char *value);
int upsert_hash_node(const char *key, const char *value, hash_node_t **head);

/**
 * hash_table_set - Set a key-value pair in a hash table
 * @ht: Pointer to the hash table
 * @key: The key to associate with the value
 * @value: The value to be stored in the hash table
 *
 * Description:
 * This function sets a key-value pair in the given hash table.
 * It calculates the hash code for the provided key and inserts the key-value
 * pair into the appropriate location in the hash table.
 *
 * Return:
 * 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int hash_code;
	hash_node_t **head, *new_node;


	if (!ht || !ht->array || !key || !*(key))
		return (0);

	hash_code = key_index((unsigned char *)key, ht->size);
	head = &(ht->array[hash_code]);


	return (upsert_hash_node(key, value, head));
}

/**
 * create_hash_node - Create a new hash node with the provided key and value
 * @key: The key for the hash node
 * @value: The value associated with the key
 *
 * Description:
 * This function allocates memory for a new hash node and initializes it with
 * the provided key and value.
 *
 * Return:
 * A pointer to the newly created hash node on success, or NULL on failure
 */
hash_node_t *create_hash_node(const char *key, const char *value)
{
	hash_node_t *node;
	char *v_dup, *k_dup;

	k_dup = strdup(key);
	v_dup = strdup(value);
	node = malloc(sizeof(hash_node_t));

	if (node == NULL || !k_dup || !v_dup)
	{
		node ? free(node) : (void *)0;
		k_dup ? free(k_dup) : (void *)0;
		v_dup ? free(v_dup) : (void *)0;
		return (NULL);
	}

	node->key = k_dup;
	node->value = v_dup;
	node->next = NULL;

	return (node);
}

/**
 * upsert_hash_node - Upsert a hash node into a linked list
 * @key: The key to associate with the value
 * @value: The value to be stored in the hash node
 * @head: Pointer to the head of the linked list
 *
 * Description:
 * This function upserts (inserts or updates) a hash node
 * with the provided key and value into the linked list pointed to by 'head'.
 * If a node with the same key already exists in the list, the function
 * updates the value. If not, it creates a new hash node and inserts it at
 * the beginning of the list.
 *
 * Return:
 * 1 on success, 0 on failure (memory allocation fails or if the 'head'
 * pointer is invalid).
 */
int upsert_hash_node(const char *key, const char *value, hash_node_t **head)
{
	hash_node_t *new_node, *current;
	char *v_dup;

	if (!head)
		return (0);

	current = *head;
	while (current)
	{
		if (strcmp(key, current->key) == 0)
		{
			v_dup = strdup(value);
			if (!v_dup)
				return (0);
			free(current->value);
			current->value = v_dup;
			return (1);
		}
		current = current->next;
	}

	new_node = create_hash_node(key, value);
	if (!new_node)
		return (0);
	new_node->next = *head;
	*head = new_node;
	return (1);
}

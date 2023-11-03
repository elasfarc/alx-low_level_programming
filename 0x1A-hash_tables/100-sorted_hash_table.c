#include "hash_tables.h"

void safe_free(void *v);


/**
 * shash_table_create - Create a sorted hash table
 * @size: The size of the hash table
 *
 * Description:
 * This function creates a sorted hash table with a specified size.
 * It allocates memory for the hash table structure and initializes its
 * elements, including the sorted linked list.
 *
 * Return:
 * A pointer to the newly created sorted hash table on success,
 * or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sorted_hash_table;
	shash_node_t **hash_data_array;
	unsigned long int i;

	sorted_hash_table = malloc(sizeof(shash_table_t));
	if (!sorted_hash_table)
		return (NULL);

	hash_data_array = malloc(sizeof(shash_node_t *) * size);
	if (!hash_data_array)
	{
		free(sorted_hash_table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		hash_data_array[i] = NULL;

	sorted_hash_table->size = size;
	sorted_hash_table->array = hash_data_array;
	sorted_hash_table->shead = NULL;
	sorted_hash_table->stail = NULL;

	return (sorted_hash_table);
}


/**
 * shash_table_get_node - Get a node by key from a sorted hash table
 * @ht: Pointer to the sorted hash table
 * @key: The key to search for
 *
 * Return:
 * A pointer to the found node on success,
 * or NULL on failure or if the node is not found.
 */
shash_node_t *shash_table_get_node(const shash_table_t *ht, const char *key)
{
	unsigned long int hash_code;
	shash_node_t *head, *current;

	if (!ht || !(ht->array) || !key || !(*key))
		return (NULL);

	hash_code = key_index((unsigned char *)key, ht->size);
	head = ht->array[hash_code];

	for (current = head; current; current = current->next)
		if (strcmp(current->key, key))
			return (current);
	return (NULL);
}


/**
 * shash_table_get - Get the value associated with a key from
 * a sorted hash table
 * @ht: Pointer to the sorted hash table
 * @key: The key to search for
 *
 * Return:
 * A pointer to the associated value on success,
 * or NULL on failure or if the key is not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;

	node = shash_table_get_node(ht, key);
	if (node)
		return (node->value);
	else
		return (NULL);
}


/**
 * shash_table_create_node - Create a new sorted hash node
 * @key: The key for the new node
 * @value: The value for the new node
 *
 * Description:
 * This function creates a new sorted hash node with the provided key and value
 *
 * Return:
 * A pointer to the newly created node on success,
 * or NULL on failure.
 */
shash_node_t *shash_table_create_node(const char *key, const char *value)
{
	shash_node_t *node;
	char *v_dup, *k_dup;

	if (!key || !value || !(*key))
		return (NULL);

	k_dup = strdup(key);
	v_dup = strdup(value);
	node = malloc(sizeof(shash_node_t));
	if (!node || !k_dup || !v_dup)
	{
		safe_free(k_dup);
		safe_free(v_dup);
		safe_free(node);
		return (NULL);
	}

	node->key = k_dup;
	node->value = v_dup;
	node->next = NULL;
	node->snext = NULL;
	node->sprev = NULL;

	return (node);
}


/**
 * insert_lexico_sorted - Insert a node into a sorted hash table
 * in lexicographical order.
 * @sht: Pointer to the sorted hash table
 * @node: Pointer to the node to be inserted
 *
 */
void insert_lexico_sorted(shash_table_t * const sht, shash_node_t * const node)
{
	shash_node_t *current;
	int is_inserted = 0;

	if (sht->shead == NULL)
	{
		node->snext = NULL;
		node->sprev = NULL;
		sht->shead = node;
		sht->stail = node;
		return;
	}

	current = sht->shead;
	for (; (current && !is_inserted); (current = current->snext))
	{
		if (strcmp(node->key, current->key) < 0)
		{
			node->snext = current;
			node->sprev = current->sprev;
			if (sht->shead == current)
				sht->shead = node;
			current->sprev ? (current->sprev->snext = node) : (void *)0;
			current->sprev = node;
			is_inserted = 1;
		}
	}

	/* at this point it's the last one' */
	if (!is_inserted)
	{
		node->snext = NULL;
		node->sprev = sht->stail;
		sht->stail->snext = node;
		sht->stail = node;
	}

}


/**
 * shash_table_set - Set a key-value pair in a sorted hash table
 * @ht: Pointer to the sorted hash table
 * @key: The key to associate with the value
 * @value: The value to be stored
 *
 * Description:
 * This function sets a key-value pair in the sorted hash table.
 * If the key already exists, it updates the value;
 * otherwise, it creates a new node and inserts it lexicographically.
 *
 * Return:
 * 1 on success, 0 on failure
 * (if memory allocation fails or if the input parameters are invalid).
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int hash_code;
	shash_node_t **head, *node;
	char *v_dup;

	if (!ht || !(ht->array) || !key || !(*key))
		return (0);

	hash_code = key_index((unsigned char *)key, ht->size);
	head = &(ht->array[hash_code]);

	node = shash_table_get_node(ht, key);
	if (node) /* update value */
	{
		v_dup = strdup(value);
		if (!v_dup)
			return (0);
		safe_free(node->value);
		node->value = v_dup;
		return (1);
	}

	node = shash_table_create_node(key, value);
	if (!node)
		return (0);
	node->next = *head;
	*head = node;

	insert_lexico_sorted(ht, node);

	return (1);
}


/**
 * shash_table_delete - Delete a sorted hash table and its elements
 * including the sorted linked list and individual nodes.
 *
 * @ht: Pointer to the sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
		return;

	while (ht->shead)
	{
		node = ht->shead;
		ht->shead = ht->shead->snext;
		safe_free(node->key);
		safe_free(node->value);
		safe_free(node);
	}

	safe_free(ht->array);
	safe_free(ht);
}


/**
 * shash_print - Print the contents of a sorted hash table
 * @ht: Pointer to the sorted hash table
 * @mode: The print mode (AZ for ascending order, ZA for descending order)
 *
 * Description:
 * This function prints the contents of a sorted hash table
 * in either ascending or descending order.
 */
void shash_print(const shash_table_t *ht, PRINT_MODE mode)
{
	unsigned long int atleast_one_printed = 0;
	shash_node_t *node;

	if (!ht)
		return;


	printf("{");
	node = mode == AZ ? ht->shead : ht->stail;
	while (node)
	{
		printf("%s'%s': '%s'",
			atleast_one_printed ? ", " : "",
			node->key, node->value
		);
		atleast_one_printed = 1;

		node = (mode == AZ) ? (node->snext) : (node->sprev);
	}
	printf("}\n");
}


/**
 * shash_table_print - Print the contents of a sorted hash table
 * in ascending order.
 * @ht: Pointer to the sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_print(ht, AZ);
}


/**
 * shash_table_print_rev - Print the contents of a sorted hash table
 * in descending order
 * @ht: Pointer to the sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_print(ht, ZA);
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

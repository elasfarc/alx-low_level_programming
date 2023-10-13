#include "lists.h"

/**
 * get_dnodeint_at_index - Get the node at a specified index
 * in a doubly linked list
 * @head: A pointer to the head of the doubly linked list
 * @index: The index of the node to retrieve (0-based)
 *
 * Return:
 * A pointer to the node at the given index or NULL if the
 * index is out of range.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i, is_match = 0;
	dlistint_t *node;

	for ((i = 0, node = head); node; (node = node->next, i++))
		if (i == index)
		{
			is_match = 1;
			break;
		}

	return (is_match ? node : NULL);

}

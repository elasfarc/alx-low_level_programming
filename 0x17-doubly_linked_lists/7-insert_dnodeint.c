#include "lists.h"

/**
 * insert_dnodeint_at_index - Insert a new node at a specific index
 * in a doubly linked list
 * @h: A pointer to a pointer to the head of the doubly linked list
 * @idx: The index at which the new node should be inserted
 * @n: The integer value to be stored in the new node
 *
 * Return:
 * A pointer to the newly added node or NULL if the index is out of range
 * or memory allocation fails.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node, *current;
	unsigned int i;

	if (!h)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));
	for ((current = *(h), i = 0); current; (current = current->next, i++))
	{
		if (current->next == NULL && idx == i + 1)
			return (add_dnodeint_end(h, n));
		if (idx == i)
		{
			node = malloc(sizeof(dlistint_t));
			if (!node)
				return (NULL);
			node->n = n;
			node->prev = current->prev;
			node->next = current;
			(current->prev)->next = node;
			current->prev = node;
			return (node);
		}
	}
	return (NULL);
}

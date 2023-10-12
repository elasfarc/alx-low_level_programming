#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * dlistint_len - get the number of in a doubly linked list
 * @h: A pointer to the head of the doubly linked list
 *
 * Return:
 * The number of nodes in the doubly linked list.
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t nodes = 0;
	const dlistint_t *current;

	for (current = h; current != NULL; current = current->next)
		nodes++;
	return (nodes);
}

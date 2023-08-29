#include <stdlib.h>
#include <stddef.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: points to the first element's pointer.
 * @idx: unsigned index of the list where the new node should be added
 *							(starts at 0)
 * @n: the integer (n) data of the new added node.
 *
 * Return: the address of the new node or (NULL) if it failed
 *	or not possible to add the new node at index idx.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *node, *current = (*head);

	if (!head)
		return (NULL);

	node = malloc(sizeof(listint_t));

	if (!node)
		return (NULL);
	node->n = n;
	node->next = NULL;

	if (idx == 0)
		return (*head = node);

	for (; (current && i < idx); current = current->next)
		if (i++ == idx - 1)
		{
			node->next = current->next;
			current->next = node;
			return (node);
		}

	free(node);
	return (NULL);
}


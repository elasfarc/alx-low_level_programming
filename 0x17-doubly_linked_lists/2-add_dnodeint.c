#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint - Add a new node at the beginning of a doubly linked list
 * @head: A pointer to a pointer to the head of the doubly linked list
 * @n: The integer value to be stored in the new node
 *
 * Return:
 * A pointer to the newly added node or NULL if memory allocation fails or if
 * the 'head' pointer is NULL.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node = NULL;

	if (head == NULL)
		return (NULL);

	node = malloc(sizeof(dlistint_t));
	if (!node)
		return (NULL);

	node->n = n;
	node->prev = NULL;
	node->next = *(head);
	*(head) ? (*(head))->prev = node : (void *)0;
	*head = node;

	return (node);
}

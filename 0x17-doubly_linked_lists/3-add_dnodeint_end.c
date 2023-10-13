#include "lists.h"

/**
 * add_dnodeint_end - Add a new node at the end of a doubly linked list
 * @head: A pointer to a pointer to the head of the doubly linked list
 * @n: The integer value to be stored in the new node
 *
 * Return:
 * A pointer to the newly added node or NULL if memory allocation fails or if
 * the 'head' pointer is NULL.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node = NULL, *tail = NULL;

	if (head == NULL)
		return (NULL);

	node = malloc(sizeof(dlistint_t));
	if (!node)
		return (NULL);

	for (tail = *(head); tail && tail->next; tail = tail->next)
		;

	node->n = n;
	node->next = NULL;
	node->prev = tail;

	tail ? (tail->next = node) : (void *)0;
	if (*(head) == NULL)
		*(head) = node;

	return (node);
}

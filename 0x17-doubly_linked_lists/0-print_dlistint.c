#include "lists.h"
/**
 * print_dlistint - Prints the elements of a doubly linked list
 * @h: A pointer to the head of the doubly linked list
 *
 * Return:
 * The number of nodes in the doubly linked list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t nodes_counter = 0;
	const dlistint_t *current;

	for (current = h; current != NULL; current = current->next)
	{
		nodes_counter++;
		printf("%d\n", current->n);
	}
	return (nodes_counter);
}

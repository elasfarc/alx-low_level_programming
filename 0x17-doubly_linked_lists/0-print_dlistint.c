#include "lists.h"

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

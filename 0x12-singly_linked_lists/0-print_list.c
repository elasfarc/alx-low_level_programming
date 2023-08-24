#include <stdio.h>
#include <stddef.h>
#include "lists.h"

/**
 * print_list - prints all the element of a list_t list.
 * @h: pointer to the list.
 *
 * Return: on success -> the number of nodes.
 */

size_t print_list(const list_t *h)
{
	size_t size = 0;
	const list_t *current;

	if (!h)
		return (0);

	current = h;

	do {
		printf(
				"[%u] %s\n",
				(current->str ? current->len : 0),
				(current->str ? current->str : "(nil)")
			);
		size++;
		current = current->next;

	} while (current != NULL);

	return (size);

}


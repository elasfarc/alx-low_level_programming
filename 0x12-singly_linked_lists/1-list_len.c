#include <stddef.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list_t list
 * @h: list to get it's length
 *
 * Return: length of the list
 */
size_t list_len(const list_t *h)
{
	const list_t *current;
	size_t size = 0;

	current = h;
	if (current == NULL)
		return (size);
	do {
		size++;
		current = current->next;

	} while (current != NULL);

	return (size);

}


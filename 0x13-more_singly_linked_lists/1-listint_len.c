#include <stddef.h>
#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked list (listint_t).
 * @h: points to the head of the list.
 *
 * Return: number of elements in the list.
 */
size_t listint_len(const listint_t *h)
{
	size_t size = 0;

	for (; h; h = h->next)
		size++;

	return (size);
}

#include <stddef.h>
#include "lists.h"
#include <stdio.h>

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: points to the list first element.
 * @index: unsigned index of the required node starting at (0).
 *
 * Return: the nth node of list or (NULL) if it does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *current = head;

	while (current && i <= index)
	{
		if (i++ == index)
			return (current);

		current = current->next;
	}

	return (NULL);
}


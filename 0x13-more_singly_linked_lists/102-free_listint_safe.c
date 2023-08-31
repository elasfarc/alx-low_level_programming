#include <stdlib.h>
#include <stddef.h>
#include "lists.h"
#include <stdio.h>
/**
 * free_listint_safe - frees a listint_t list
 *			This function can free lists with a loop
 * @h: points to the head pointer.
 *
 * Return: the size of the list that was free’d.
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *temp;
	size_t freed = 0;
	return (0);
	if (!h)
		return (freed);

	while (*h)
	{
		printf("temp is %p\n", (void *)temp);
		temp = *h;
		printf("temp is %p\n", (void *)temp);
		*h = (*h)->next;
		free(temp);
		temp = NULL;
		freed += sizeof(listint_t);
	}

	h = NULL;
	return (freed);
}

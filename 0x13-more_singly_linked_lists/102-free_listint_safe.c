#include <stdlib.h>
#include <stddef.h>
#include "lists.h"
/**
 * free_listint_safe - frees a listint_t list
 *			This function can free lists with a loop
 * @h: points to the head pointer.
 *
 * Return: the size of the list that was free’d.
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *outer, *iner, *temp, *loop = NULL;
	size_t freed = 0, outer_steps = 0, i;

	if (!h)
		return (freed);

	outer = *h;
	while (outer)
	{
		outer = outer->next;
		outer_steps++;

		for (i = 0, iner = (*h); i < outer_steps; i++)
		{
			if (outer == iner)
				loop = outer;
			iner = iner->next;
		}
		if (loop)
			break;
	}


	i = 0;
	while (*h)
	{
		if (loop && *h == loop && ++i > 1)
		{
			*h = NULL;
			break;
		}
		temp = *h;
		*h = (*h)->next;
		free(temp);
		freed += sizeof(listint_t);
	}
	h = NULL;
	return (freed);
}

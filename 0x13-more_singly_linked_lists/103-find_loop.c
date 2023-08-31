#include <stddef.h>
#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: points to the First element in the list.
 *
 * Return: The address of the node where the loop starts,
 *		or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *outer, *iner;
	int outer_steps, i;

	outer_steps = head ? 1 : 0;
	outer = head;
	while (outer)
	{
		outer = outer->next;
		outer_steps++;
		iner = head;
		for (i = 1; i < outer_steps; i++)
		{
			if (outer == iner)
				return (outer);
			iner = iner->next;
		}
	}

	return (NULL);
}


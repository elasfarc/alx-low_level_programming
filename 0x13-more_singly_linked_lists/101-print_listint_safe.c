#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list.
 *		(could handle lists with a loop)
 * @head: points to the first elment.
 *
 * Return: the number of nodes in the list.
 *	on failure exit with status (98)
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *outer, *iner, *safe;
	size_t steps = 0, i;


	safe = head;
	outer = head;
	while (outer)
	{
		printf("[%p] %d\n", (void *)safe, safe->n);

		outer = outer->next;
		steps++;

		iner = head;
		for (i = 0; i < steps; i++)
		{
			if (iner == outer)
			{
				printf("-> [%p] %d\n", (void *)outer, outer->n);
				exit(98);
			}
			iner = iner->next;
		}

		safe = outer;
	}

	return (steps);
}


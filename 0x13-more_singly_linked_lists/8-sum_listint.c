#include <stddef.h>
#include "lists.h"

/**
 * sum_listint - returns the sum of all the data(n) of a listint_t linked list
 * @head: points to the first element of the list.
 *
 * Return: the sum of all data(n) or 0 if the list is empy.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	while (current)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}


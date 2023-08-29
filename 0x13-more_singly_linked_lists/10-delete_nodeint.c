#include <stdlib.h>
#include <stddef.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node
 *		at the index @index of a listint_t l-list.
 * @head: points to the head pointer.
 * @index: the index of the node to be deleted (starts at 0).
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int i = 0;

	if (!head || !(*head))
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}
	while (current && i < index)
	{
		if (i == index - 1)
		{
			temp = current->next;
			current->next = current->next->next;
			free(temp);
			return (1);
		}
		current = current->next;
		i++;
	}
	return (-1);
}


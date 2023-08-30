#include <stddef.h>
#include "lists.h"
#include <stdio.h>

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: points to the the head pointer
 *
 * Return: a pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *temp = NULL;

	if (!head || !(*head))
		return (NULL);
	while ((*head)->next)
	{
		temp = (*head)->next;
		(*head)->next = prev;
		prev = (*head);
		(*head) = temp;
	}

	(*head)->next = prev;
	return (*head);
}


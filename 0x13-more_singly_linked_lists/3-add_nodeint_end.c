#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list.
 * @head: pointer to the head of the list pointer.
 * @n: Integer to be stored in the list.
 *
 * Return: the address of the new element or NULL if failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *node, *tail;

	if (!head)
		return (NULL);

	node = malloc(sizeof(listint_t));
	if (!node)
		return (NULL);

	node->n = n;
	node->next = NULL;

	tail = *head;
	while (tail && tail->next)
		tail = tail->next;

	if (tail)
		tail->next = node;
	else
		*head = node;

	return (node);
}


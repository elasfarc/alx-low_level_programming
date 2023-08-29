#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list.
 * @head: points to the head of the list.
 * @n: integer to be add to the list.
 *
 * Return: the address of the new element or NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *node;

	node = malloc(sizeof(listint_t));

	if (!head || !node)
		return (NULL);

	node->n = n;
	node->next = (*head);
	*head = node;

	return (node);

}


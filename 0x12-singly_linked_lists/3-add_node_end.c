#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list.
 * @head: head of the list.
 * @str: string to be added to the newly created node.
 *
 * Return: the address of the new element or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node, *tail;
	char *node_str;

	node = malloc(sizeof(list_t));
	if (!head || !node)
		return (NULL);

	node_str = strdup(str);
	if (!node_str)
	{
		free(node);
		return (NULL);
	}

	tail = *head;

	while (tail && tail->next)
		tail = tail->next;


	if (tail)
		tail->next = node;
	else
		*head = node;

	node->str = node_str;
	node->len = _strlen(node_str);
	node->next = NULL;

	return (node);

}


/**
 * _strlen - return the length of a string
 * @s: the string.
 *
 * Return: always unsigned int - the length of the string.
 */
unsigned int _strlen(const char *s)
{
	return (s[0] == '\0'
			? 0
			: 1 + _strlen(s + 1));
}


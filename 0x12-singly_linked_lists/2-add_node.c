#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
#include <stdio.h>

unsigned int _strlen(const char *s);

/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: head of the list_t list.
 * @str: string to be added into the new created node.
 *
 * Return: the address of the new element or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *node;
	char *node_str;

	node = malloc(sizeof(list_t));
	node_str = strdup(str);

	if (!node || !node_str)
		return (NULL);

	node->str = node_str;
	node->len = _strlen(node_str);
	node->next = *head;
	*head = node;

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


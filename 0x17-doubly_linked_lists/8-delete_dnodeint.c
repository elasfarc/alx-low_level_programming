#include "lists.h"

#define DELETE_SUCCESS (1)
#define DELETE_FAIL (-1)

/**
 * delete_dnodeint_at_index - Delete a node at a specific index in
 * a doubly linked list
 * @head: A pointer to a pointer to the head of the doubly linked list
 * @index: The index of the node to be deleted (0-based)
 *
 * Description:
 * This function deletes a node at the specified index in a doubly linked list.
 * If the index is out of range or the list is empty, it returns DELETE_FAIL.
 * If the node is successfully deleted, it returns DELETE_SUCCESS.
 * The head pointer is updated if the first node is deleted.
 *
 * Return:
 * DELETE_SUCCESS if the node is successfully deleted, DELETE_FAIL otherwise.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{

	dlistint_t *current;
	unsigned int i = 0;

	if (!head || !(*head))
		return (DELETE_FAIL);

	for (current = (*head); current; (current = current->next, i++))
		if (index == i)
		{
			current->next ? current->next->prev = current->prev : (void *)0;
			current->prev
				? current->prev->next = current->next
				: (*head = current->next);
			free(current);
			return (DELETE_SUCCESS);
		}
	return (DELETE_FAIL);
}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
#include <stddef.h>
int main(void)
{

	size_t w = print_listint_safe(NULL);
	printf("null case %lu\n", w);

	listint_t *head = NULL;
	listint_t *current = NULL;
	listint_t *n121 = NULL;
for (int i = 1; i <= 150; i++) {
    listint_t *new_node = malloc(sizeof(listint_t));
    new_node->n = i;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        current = new_node;
    } else {
        current->next = new_node;
        current = new_node;
    }
    if (i == 121) {
    	n121 = current;
    }
}
//current->next = n121;
size_t l = print_listint_safe(head);
printf("%lu elements\n", l);
	return (0);
}

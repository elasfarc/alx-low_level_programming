#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

int main(void)
{

	listint_t *node1 = malloc(sizeof(listint_t));
	listint_t *node2 = malloc(sizeof(listint_t));
	node1->n = 1;
	node2->n = 2;
	node1->next = node2;
	node2->next = node1;
	print_listint_safe(node1);
	
	printf("=====================\n");


	return (0);
}

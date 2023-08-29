#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

void test_insert_nodeint_at_index_empty_list() {
    listint_t *head = NULL;
    listint_t *node = insert_nodeint_at_index(&head, 0, 42);
    if (node == NULL) {
        printf("test_insert_nodeint_at_index_empty_list failed: returned NULL\n");
    }
    if (node->n != 42) {
        printf("test_insert_nodeint_at_index_empty_list failed: node data is incorrect\n");
    }
    if (head != node) {
        printf("test_insert_nodeint_at_index_empty_list failed: head pointer is incorrect\n");
    }

    printf("test_insert_nodeint_at_index_empty_list passed\n");
	free_listint2(&head);
}

void test_insert_nodeint_at_index_nonempty_list() {
    listint_t *head = NULL;
    insert_nodeint_at_index(&head, 0, 1);
    insert_nodeint_at_index(&head, 1, 3);
    insert_nodeint_at_index(&head, 2, 5);
    listint_t *node = insert_nodeint_at_index(&head, 0, -1);
    if (node == NULL) {
        printf("test_insert_nodeint_at_index_nonempty_list failed: returned NULL\n");
    }
    if (node->n != -1) {
        printf("test_insert_nodeint_at_index_nonempty_list failed: node data is incorrect\n");
    }
    if (head != node) {
        printf("test_insert_nodeint_at_index_nonempty_list failed: head pointer is incorrect\n");
    }
    printf("test_insert_nodeint_at_index_nonempty_list passed\n");
	free_listint2(&head);
}

void test_insert_nodeint_at_index_end_of_list() {
    listint_t *head = NULL;
    insert_nodeint_at_index(&head, 0, 1);
    insert_nodeint_at_index(&head, 1, 3);
    insert_nodeint_at_index(&head, 2, 5);
    listint_t *node = insert_nodeint_at_index(&head, 3, 7);
    if (node == NULL) {
        printf("test_insert_nodeint_at_index_end_of_list failed: returned NULL\n");
    }
    if (node->n != 7) {
        printf("test_insert_nodeint_at_index_end_of_list failed: node data is incorrect\n");
    }
    if (head->next->next->next != node) {
        printf("test_insert_nodeint_at_index_end_of_list failed: node is not at the end of the list\n");
    }
    printf("test_insert_nodeint_at_index_end_of_list passed\n");
	free_listint2(&head);
}

void test_insert_nodeint_at_index_index_greater_than_length() {
    listint_t *head = NULL;
    insert_nodeint_at_index(&head, 0, 1);
    insert_nodeint_at_index(&head, 1, 3);
    insert_nodeint_at_index(&head, 2, 5);
    listint_t *node = insert_nodeint_at_index(&head, 5, 7);
    if (node != NULL) {
        printf("test_insert_nodeint_at_index_index_greater_than_length failed: returned non-NULL\n");
    }
    printf("test_insert_nodeint_at_index_index_greater_than_length passed\n");
	free_listint2(&head);
}

void test_insert_nodeint_at_index_negative_index() {
    listint_t *head = NULL;
    insert_nodeint_at_index(&head, 0, 1);
    insert_nodeint_at_index(&head, 1, 3);
    insert_nodeint_at_index(&head, 2, 5);
    listint_t *node = insert_nodeint_at_index(&head, -1, 7);
    if (node != NULL) {
        printf("test_insert_nodeint_at_index_negative_index failed: returned non-NULL\n");
    }
    printf("test_insert_nodeint_at_index_negative_index passed\n");
	free_listint2(&head);
}

int main(void) {
    test_insert_nodeint_at_index_empty_list();
    test_insert_nodeint_at_index_nonempty_list();
    test_insert_nodeint_at_index_end_of_list();
    test_insert_nodeint_at_index_index_greater_than_length();
    test_insert_nodeint_at_index_negative_index();
    return 0;
}

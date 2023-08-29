#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


void test_delete_head_node_one_node() {
    listint_t *head = malloc(sizeof(listint_t));
    head->n = 1;
    head->next = NULL;
    int result = delete_nodeint_at_index(&head, 0);
    printf("Test delete_head_node_one_node: %s\n", result == 1 ? "Passed" : "Failed");
    free(head);
}

void test_delete_head_node_multiple_nodes() {
    listint_t *head = malloc(sizeof(listint_t));
    head->n = 1;
    head->next = malloc(sizeof(listint_t));
    head->next->n = 2;
    head->next->next = NULL;
    int result = delete_nodeint_at_index(&head, 0);
    printf("Test delete_head_node_multiple_nodes: %s\n", result == 1 ? "Passed" : "Failed");
    free(head->next);
    free(head);
}

void test_delete_middle_node() {
    listint_t *head = malloc(sizeof(listint_t));
    head->n = 1;
    head->next = malloc(sizeof(listint_t));
    head->next->n = 2;
    head->next->next = malloc(sizeof(listint_t));
    head->next->next->n = 3;
    head->next->next->next = NULL;
    int result = delete_nodeint_at_index(&head, 1);
    printf("Test delete_middle_node: %s\n", result == 1 ? "Passed" : "Failed");
    //free(head->next->next);
   // free(head->next);
   // free(head);
}

void test_delete_last_node() {
    listint_t *head = malloc(sizeof(listint_t));
    head->n = 1;
    head->next = malloc(sizeof(listint_t));
    head->next->n = 2;
    head->next->next = malloc(sizeof(listint_t));
    head->next->next->n = 3;
    head->next->next->next = NULL;
    printf("b4 deleting ====\n");
    int result = delete_nodeint_at_index(&head, 2);
    printf("after deletiing =====\n");
    printf("Test delete_last_node: %s\n", result == 1 ? "Passed" : "Failed");
    //free(head->next->next);
    //free(head->next);
    //free(head);
}

int main() {
    test_delete_head_node_one_node();
    test_delete_head_node_multiple_nodes();
    test_delete_middle_node();
    test_delete_last_node();

    return 0;
}

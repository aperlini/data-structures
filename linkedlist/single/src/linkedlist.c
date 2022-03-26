#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node_t;

Node_t *new_node(int n) {
    Node_t *node = (Node_t *) malloc(sizeof(Node_t));
    node->value = n;
    node->next = NULL;
    return node;
}

Node_t *insert_to_top(Node_t *head, Node_t *to_insert) {
    to_insert->next = head;
    return to_insert;
}

int free_memory(Node_t *head) {
    Node_t *current = head;
    while(current != NULL) {
        free(current);
        current = current->next;
    }
    return 0;
}

void printlist(Node_t *head) {
    Node_t *current = head;
    while(current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL \n");
}


int main() {

    Node_t *head = NULL; 
    Node_t *tmp = NULL;

    tmp = new_node(33);
    head = insert_to_top(head, tmp);

    tmp = new_node(32);
    head = insert_to_top(head, tmp);

    tmp = new_node(42);
    head = insert_to_top(head, tmp);
    
    printlist(head);

    if(free_memory(head) < 0) {
        perror("free malloc");
    }

    return EXIT_SUCCESS;
    
}

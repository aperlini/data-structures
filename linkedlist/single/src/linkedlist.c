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

// return address of new head
Node_t *insert_top(Node_t *head, Node_t *node) {
    node->next = head;
    return node;
}

void insert_bottom(Node_t *head, Node_t *node) {
    Node_t *current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = node;
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
    head = insert_top(head, tmp);

    tmp = new_node(32);
    head = insert_top(head, tmp);

    tmp = new_node(42);
    head = insert_top(head, tmp);

    tmp = new_node(33);
    insert_bottom(head, tmp);

    tmp = new_node(23);
    insert_bottom(head, tmp);

    tmp = new_node(24);
    insert_bottom(head, tmp);
    
    printlist(head);

    if(free_memory(head) < 0) {
        perror("free malloc");
    }

    return EXIT_SUCCESS;
    
}

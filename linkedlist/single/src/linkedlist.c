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


Node_t *insert_top(Node_t *head, Node_t *node) {
    node->next = head;
    return node; // return address of new head
}

void insert_bottom(Node_t *head, Node_t *node) {
    Node_t *current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = node;
}

void insert_before(Node_t *predecessor, Node_t *node_to_insert) {
    node_to_insert->next = predecessor->next;
    predecessor->next = node_to_insert;
}

Node_t *get_predecessor_of(Node_t *head, int value) {
    Node_t *current = head;
    while(current->next->value != value) {
        current = current->next;
    }
    return current;
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

    head = insert_top(head, new_node(33));
    head = insert_top(head, new_node(32));
    head = insert_top(head, new_node(42));

    insert_bottom(head, new_node(23));
    insert_bottom(head, new_node(24));

    Node_t *predecessor = get_predecessor_of(head, 23);
    insert_before(predecessor, new_node(99));
    predecessor = get_predecessor_of(head, 99);
    insert_before(predecessor, new_node(101));
    
    printlist(head);

    if(free_memory(head) < 0) {
        perror("free malloc");
    }

    return EXIT_SUCCESS;
    
}

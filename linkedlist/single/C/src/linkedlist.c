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

void insert(Node_t *from, Node_t *to) {
    to->next = from->next;
    from->next = to;
}

Node_t *get_node(Node_t *head, int value) {
    Node_t *current = head;
    while(current->value != value) {
        current = current->next;
    }
    return current;
}

Node_t *get_predecessor_of(Node_t *head, int value) {
    Node_t *current = head;
    while(current->next->value != value) {
        current = current->next;
    }
    return current;
}

void delete_last_node(Node_t *head) {
    Node_t *current = head;
    while(current->next->next != NULL) {
        current = current->next;
    }
    current->next = NULL;
    free(current->next);
}

Node_t *delete_first_node(Node_t *head) {
    Node_t *new_head = head->next;
    free(head);
    return new_head;
}

int free_memory(Node_t *head) {
    Node_t *current = head;
    while(current != NULL) {
        free(current);
        current = current->next;
    }
    return 0;
}

void print_list(Node_t *head) {
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
    insert(predecessor, new_node(99));
    predecessor = get_predecessor_of(head, 99);
    insert(predecessor, new_node(101));
    
    Node_t *successor = get_node(head, 23);
    insert(successor, new_node(25));
    insert(get_node(head, 32), new_node(35));

    print_list(head);

    delete_last_node(head);
    print_list(head);

    delete_last_node(head);
    print_list(head);

    head = delete_first_node(head);
    print_list(head);

    if(free_memory(head) < 0) {
        perror("free malloc");
    }

    return EXIT_SUCCESS;
    
}

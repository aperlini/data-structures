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

void insert(Node_t *from, Node_t *to) {
    to->next = from->next;
    from->next = to;
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

void insert_before(Node_t *head, int value_predecessor, Node_t *node) {
    Node_t *predecessor = get_predecessor_of(head, value_predecessor);
    insert(predecessor, node);
}

void insert_after(Node_t *head, int value_successor, Node_t *node) {
    insert(get_node(head, value_successor), node);
}

void delete_last_node(Node_t *head) {
    Node_t *current = head;
    while(current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

Node_t *delete_first_node(Node_t *head) {
    Node_t *new_head = head->next;
    free(head);
    return new_head;
}

void delete_at_position(Node_t *head, int value) {
    Node_t *to_be_deleted = get_node(head, value);
    Node_t *predecessor = get_predecessor_of(head, value);
    predecessor->next = to_be_deleted->next;
    free(to_be_deleted);
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

    printf("insert at top: \n");
    head = insert_top(head, new_node(33));
    print_list(head);

    head = insert_top(head, new_node(32));
    print_list(head);

    head = insert_top(head, new_node(42));
    print_list(head);

    printf("insert at bottom: \n");
    insert_bottom(head, new_node(23));
    print_list(head);

    insert_bottom(head, new_node(24));
    print_list(head);

    printf("insert before: \n");
    insert_before(head, 23, new_node(99));
    print_list(head);

    insert_before(head, 99, new_node(101));
    print_list(head);
    
    printf("insert after: \n");
    insert_after(head, 23, new_node(25));
    print_list(head);

    insert_after(head, 32, new_node(35));
    print_list(head);

    printf("delete last node: \n");
    delete_last_node(head);
    print_list(head);

    delete_last_node(head);
    print_list(head);

    printf("delete first node: \n");
    head = delete_first_node(head);
    print_list(head);

    printf("delete at position: \n");
    delete_at_position(head, 99);
    print_list(head);

    if(free_memory(head) < 0) {
        perror("free malloc");
    }

    return EXIT_SUCCESS;
    
}

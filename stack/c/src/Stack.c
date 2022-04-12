#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node_t;

typedef struct Stack {
    Node_t *first;
    int n_nodes;
} Stack_t;

void push(Stack_t *stack, Node_t *node) {
    if(node == NULL) {
        perror("node");
        exit(EXIT_FAILURE);
    }

    if(stack->first == NULL) {
        stack->first = node;
    } else {
        Node_t *old = stack->first;
        node->next = old;
        stack->first = node;
    }
    stack->n_nodes++;
}

Node_t *peek(Stack_t *stack) {
    return stack->first;
}

Node_t *pop(Stack_t *stack) {
    Node_t *old_first = stack->first;
    stack->first = old_first->next;
    stack->n_nodes--;
    return old_first;
}

Stack_t *create_stack() {
    Stack_t *stack = (Stack_t *) malloc(sizeof(Stack_t));
    stack->first = NULL;
    stack->n_nodes = 0;
    return stack;
}

Node_t *create_node(int value) {
    Node_t *n = (Node_t *) malloc(sizeof(Node_t));
    n->value = value;
    n->next = NULL;
    return n;
}

bool isEmpty(Stack_t *stack) {
    return stack->n_nodes == 0;
}

void printStack(Stack_t *stack) {
    Node_t *current = stack->first;
    while(current != NULL) {
        printf("%d\n", current->value);
        printf("v\n");
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Node_t *n = create_node(23);
    // printf("new node n value is %d\n", n->value);
    // free(n);

    Stack_t *stack = create_stack();

    printf("isEmpty : %s\n", isEmpty(stack) ? "true" : "false");

    push(stack, create_node(23));
    push(stack, create_node(32));
    push(stack, create_node(42));
    push(stack, create_node(24));
    push(stack, create_node(101));
    printStack(stack);

    printf("stack nbr elements : %d\n", stack->n_nodes);

    printf("isEmpty : %s\n", isEmpty(stack) ? "true" : "false");

    Node_t *top_element = peek(stack);
    printf("top element value : %d\n", top_element->value);

    printStack(stack);
    Node_t *top = pop(stack);
    printf("top element to be popped : %d\n", top->value);
    free(top);

    printStack(stack);

    printf("stack implementation  \n");
}

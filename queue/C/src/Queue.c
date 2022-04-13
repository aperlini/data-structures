#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node_t;

typedef struct Queue {
    Node_t *first;
    Node_t *last;
    int n_nodes;
} Queue_t;

/**
 * Add node to the queue 
 */
void enqueue(Queue_t *q, Node_t *node) {

    if(q->first == NULL && q->last == NULL) {
        q->first = node;
        q->last = node;
    } else {
        q->last->next = node;
        q->last = node;
    }
    q->n_nodes++;
}

/**
 * Remove node from the queue 
 */
Node_t *dequeue(Queue_t *q) {
    Node_t *old_first = q->first;
    q->first = q->first->next;
    old_first->next = NULL;
    q->n_nodes--;
    return old_first;
}

/**
 * Get first node of queue
 */
Node_t *front(Queue_t *q) {
    return q->first;
}

/**
 * Get last node of queue
 */
Node_t *rear(Queue_t *q) {
    return q->last;
}

/**
 * Return size of queue
 */
int size(Queue_t *q) {
    return q->n_nodes; 
}

/**
 * Check if empty
 */
bool isEmpty(Queue_t *q) {
    return q->n_nodes == 0;
}

/**
 * Queue creation
 */
Queue_t *create_queue() {
    Queue_t *q = (Queue_t *)malloc(sizeof(Queue_t));
    q->first = NULL;
    q->last = NULL;
    q->n_nodes = 0;
    return q;
}

/**
 * Print queue
 */
void printQueue(Queue_t *q) {
    Node_t *current = q->first;
    int nodes_count = q->n_nodes;
    while(nodes_count) {
        printf("%d -> ", current->value);
        current = current->next;
        nodes_count--;
    }
    printf("NULL\n");
}

/**
 * Create node
 */
Node_t *create_node(int value) {
    Node_t *n = (Node_t*)malloc(sizeof(Node_t));
    n->value = value;
    n->next = NULL;
    return n;
}

int main() {
    
    Queue_t *q = create_queue();

    printf("isEmpty : %s\n", isEmpty(q) ? "true" : "false");

    enqueue(q, create_node(23));
    enqueue(q, create_node(32));
    enqueue(q, create_node(42));

    printf("size of queue : %d\n", size(q));
    printf("isEmpty : %s\n", isEmpty(q) ? "true" : "false");

    printQueue(q);

    Node_t *first = front(q);
    Node_t *last = rear(q);

    printf("Front node in queue : %d\n", first->value);
    printf("Last node in queue : %d\n", last->value);

    Node_t *old_first = dequeue(q);
    printf("%d dequeued from queue\n", old_first->value);
    free(old_first);

    printQueue(q);
    
    enqueue(q, create_node(123));
    enqueue(q, create_node(321));
    enqueue(q, create_node(421));
    enqueue(q, create_node(213));
    enqueue(q, create_node(132));
    enqueue(q, create_node(124));

    printQueue(q);

    old_first = dequeue(q);
    printf("%d dequeued from queue\n", old_first->value);
    old_first = dequeue(q);
    printf("%d dequeued from queue\n", old_first->value);
    old_first = dequeue(q);
    printf("%d dequeued from queue\n", old_first->value);

    printf("size of queue : %d\n", size(q));

    printQueue(q);

    printf("queue implementation  \n");
}

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct node node_t;
struct node {
    void *data;
    struct node *next;
};

typedef struct queue queue_t;
struct queue {
    struct node *head;
    struct node *tail;
    void (*free_node)(void *);
    int length;
};

queue_t* init_queue(void (*free_node)(void *));
void enqueue(queue_t *queue, void *data);
void dequeue(queue_t* queue);
void free_queue(queue_t* queue);

#endif

#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_node
{
    int value;
    struct queue_node *next;
} QUEUE_NODE;

typedef struct Queue
{
    QUEUE_NODE *front;
    QUEUE_NODE *rear;
    int size;
} QUEUE;

QUEUE *create_queue(int amount);

int enqueue(QUEUE *queue, int value);
int dequeue(QUEUE *queue, int *value);
int peek_queue(QUEUE *queue, int *value);
int isEmpty_queue(QUEUE *queue);

void print_queue(QUEUE *queue);
void free_queue(QUEUE *queue);

#endif
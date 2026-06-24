#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

QUEUE *create_queue(int amount)
{
    QUEUE *queue = malloc(sizeof(QUEUE));

    if (queue == NULL)
        return NULL;

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    for (int i = 1; i <= amount; i++)
    {
        enqueue(queue, i);
    }

    return queue;
}

int isEmpty_queue(QUEUE *queue)
{
    return queue == NULL || queue->front == NULL;
}

int enqueue(QUEUE *queue, int value)
{
    if (queue == NULL)
        return 0;

    QUEUE_NODE *newNode = malloc(sizeof(QUEUE_NODE));

    if (newNode == NULL)
        return 0;

    newNode->value = value;
    newNode->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;

    return 1;
}

int dequeue(QUEUE *queue, int *value)
{
    if (isEmpty_queue(queue))
        return 0;

    QUEUE_NODE *temp = queue->front;

    if (value != NULL)
        *value = temp->value;

    queue->front = temp->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);

    queue->size--;

    return 1;
}

int peek_queue(QUEUE *queue, int *value)
{
    if (isEmpty_queue(queue))
        return 0;

    if (value != NULL)
        *value = queue->front->value;

    return 1;
}

void print_queue(QUEUE *queue)
{
    if (queue == NULL)
        return;

    QUEUE_NODE *current = queue->front;

    printf("Front -> ");

    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("<- Rear\n");
}

void free_queue(QUEUE *queue)
{
    if (queue == NULL)
        return;

    QUEUE_NODE *current = queue->front;

    while (current != NULL)
    {
        QUEUE_NODE *temp = current;
        current = current->next;
        free(temp);
    }

    free(queue);
}
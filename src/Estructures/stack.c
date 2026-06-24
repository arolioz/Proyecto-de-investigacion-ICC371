#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

STACK *create_stack(int amount)
{
    STACK *stack = malloc(sizeof(STACK));

    if (stack == NULL)
        return NULL;

    stack->top = NULL;

    for (int i = 1; i <= amount; i++)
    {
        push(stack, i);
    }

    return stack;
}

int isEmpty(STACK *stack)
{
    if (stack == NULL)
        return 1;

    return stack->top == NULL;
}

int push(STACK *stack, int value)
{
    if (stack == NULL)
        return 0;

    STACK_NODE *newNode = malloc(sizeof(STACK_NODE));

    if (newNode == NULL)
        return 0;

    newNode->value = value;
    newNode->next = stack->top;

    stack->top = newNode;

    return 1;
}

int pop(STACK *stack, int *value)
{
    if (stack == NULL || stack->top == NULL)
        return 0;

    STACK_NODE *temp = stack->top;

    if (value != NULL)
        *value = temp->value;

    stack->top = temp->next;

    free(temp);

    return 1;
}

int peek(STACK *stack, int *value)
{
    if (stack == NULL || stack->top == NULL)
        return 0;

    if (value != NULL)
        *value = stack->top->value;

    return 1;
}

void print_stack(STACK *stack)
{
    if (stack == NULL)
        return;

    STACK_NODE *current = stack->top;

    printf("Top -> ");

    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

void free_stack(STACK *stack)
{
    if (stack == NULL)
        return;

    STACK_NODE *current = stack->top;

    while (current != NULL)
    {
        STACK_NODE *temp = current;
        current = current->next;
        free(temp);
    }

    free(stack);
}
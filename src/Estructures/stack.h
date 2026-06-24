#ifndef STACK_H
#define STACK_H

typedef struct stack_node
{
    int value;
    struct stack_node *next;
} STACK_NODE;

typedef struct Stack
{
    STACK_NODE *top;
} STACK;


STACK *create_stack(int amount);


int push(STACK *stack, int value);
int pop(STACK *stack, int *value);
int peek(STACK *stack, int *value);
int isEmpty(STACK *stack);


void print_stack(STACK *stack);
void free_stack(STACK *stack);

#endif
// Estructuras.h

#ifndef LINKEDLIST_H  // Header guard: Checks if MATH_UTILS_H is not defined
#define LINKEDLIST_H   // Defines MATH_UTILS_H to prevent duplication

typedef struct node
{
    int value;
    struct node *next;
}NODE;


typedef struct LinkedList
{
    NODE *head;
    NODE *tail;
}LINKED_LIST;

LINKED_LIST *create(int value, int amount);
int add(int a, int b);
int multiply(int a, int b);

#endif // ESTRUCTURAS_H 
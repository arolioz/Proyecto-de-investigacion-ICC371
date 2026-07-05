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
}LINKED_LIST;

LINKED_LIST *create_linkedList(int amount);
int insertar_linkedList(LINKED_LIST *list, int value);
int buscar_linkedList(LINKED_LIST *list, int value);
int eliminar_linkedList(LINKED_LIST *list, int value);
void mostrar_linkedList(LINKED_LIST *list);

void free_linkedList(LINKED_LIST *list);

int add(int a, int b);
int multiply(int a, int b);

#endif // ESTRUCTURAS_H 
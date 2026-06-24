#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int add(int a,int b){
    return (a+b);
}


LINKED_LIST *create_linkedList(int amount)
{
    LINKED_LIST *list = (LINKED_LIST *)malloc(sizeof(LINKED_LIST));

    if (list == NULL)
        return NULL;

    list->head = NULL;

    for (int i = 0; i < amount; i++)
    {
        insertar_linkedList(list, i+1);
    }

    return list;
}

int insertar_linkedList(LINKED_LIST *list, int value)
{
    if (list == NULL)
        return 0;

    NODE *newNode = (NODE *)malloc(sizeof(NODE));

    if (newNode == NULL)
        return 0;

    newNode->value = value;
    newNode->next = NULL;

    // Lista vacía
    if (list->head == NULL)
    {
        list->head = newNode;
        return 1;
    }

    // Buscar el último nodo
    NODE *current = list->head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;

    return 1;
}

int eliminar_linkedList(LINKED_LIST *list, int value)
{
   

    if (list == NULL || list->head == NULL)
        return 0;

    NODE *current = list->head;
    NODE *previous = NULL;

    while (current != NULL)
    {
        if (current->value == value)
        {
            // Si es el primer nodo
            if (previous == NULL)
            {
                list->head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            free(current);
            return 1;
        }

        previous = current;
        current = current->next;
    }

    return 0; // No se encontró el valor
}

int buscar_linkedList(LINKED_LIST *list, int value)
{
    if (list == NULL)
        return -1;

    NODE *current = list->head;
    int index = 0;

    while (current != NULL)
    {
        if (current->value == value)
            return index;

        current = current->next;
        index++;
    }

    return -1;
}

void mostrar_linkedList(LINKED_LIST *lista){
    NODE *head = lista->head;
    NODE *next = head;

    while (next != NULL)
    {
        printf("[%i]",next->value);
        next = next->next;
    }
    printf("\n");
}
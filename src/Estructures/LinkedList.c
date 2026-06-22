#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int add(int a,int b){
    return (a+b);
}

LINKED_LIST *create(int value, int amount)
{
    LINKED_LIST *list = (LINKED_LIST *)malloc(sizeof(LINKED_LIST));

    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->tail = NULL;

    for (int i = 0; i < amount; i++)
    {
        NODE *newNode = (NODE *)malloc(sizeof(NODE));

        if (newNode == NULL)
            return list; // o manejar el error apropiadamente

        newNode->value = value;
        newNode->next = NULL;

        if (list->head == NULL)
        {
            list->head = newNode;
            list->tail = newNode;
        }
        else
        {
            list->tail->next = newNode;
            list->tail = newNode;
        }
    }

    return list;
}

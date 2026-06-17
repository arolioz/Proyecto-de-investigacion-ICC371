#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int add(int a,int b){
    return (a+b);
}

LINKED_LIST *create(int value){
    LINKED_LIST *new = (LINKED_LIST*)malloc(sizeof(LINKED_LIST) * 1);
    new->value = 10;

    return new;
}
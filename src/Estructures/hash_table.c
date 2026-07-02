#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"


// Función hash
int hash_function(int value)
{
    if(value < 0)
        value = -value;

    return value % TABLE_SIZE;
}


// Crear tabla hash con cantidad inicial de valores
HASH_TABLE *create_hash_table(int amount)
{
    HASH_TABLE *hash = malloc(sizeof(HASH_TABLE));

    if(hash == NULL)
        return NULL;


    for(int i = 0; i < TABLE_SIZE; i++)
    {
        hash->table[i] = NULL;
    }


    // Agregar valores iniciales de 1 hasta amount
    for(int i = 1; i <= amount; i++)
    {
        insert_hash(hash, i);
    }


    return hash;
}


// Insertar un valor
int insert_hash(HASH_TABLE *hash, int value)
{
    if(hash == NULL)
        return 0;


    int index = hash_function(value);


    HASH_NODE *newNode = malloc(sizeof(HASH_NODE));


    if(newNode == NULL)
        return 0;


    newNode->value = value;

    // Manejo de colisiones
    newNode->next = hash->table[index];

    hash->table[index] = newNode;


    return 1;
}


// Buscar un valor
int search_hash(HASH_TABLE *hash, int value)
{
    if(hash == NULL)
        return 0;


    int index = hash_function(value);


    HASH_NODE *current = hash->table[index];


    while(current != NULL)
    {
        if(current->value == value)
            return index;


        current = current->next;
    }


    return -1;
}


// Eliminar un valor
int delete_hash(HASH_TABLE *hash, int value)
{
    if(hash == NULL)
        return 0;


    int index = hash_function(value);


    HASH_NODE *current = hash->table[index];
    HASH_NODE *previous = NULL;


    while(current != NULL)
    {
        if(current->value == value)
        {
            if(previous == NULL)
                hash->table[index] = current->next;
            else
                previous->next = current->next;


            free(current);

            return 1;
        }


        previous = current;
        current = current->next;
    }


    return 0;
}


// Mostrar tabla
void print_hash(HASH_TABLE *hash)
{
    if(hash == NULL)
        return;


    for(int i = 0; i < TABLE_SIZE; i++)
    {
        printf("[%d]: ", i);


        HASH_NODE *current = hash->table[i];


        while(current != NULL)
        {
            printf("%d -> ", current->value);

            current = current->next;
        }


        printf("NULL\n");
    }
}


// Liberar memoria
void free_hash(HASH_TABLE *hash)
{
    if(hash == NULL)
        return;


    for(int i = 0; i < TABLE_SIZE; i++)
    {
        HASH_NODE *current = hash->table[i];


        while(current != NULL)
        {
            HASH_NODE *temp = current;

            current = current->next;

            free(temp);
        }
    }


    free(hash);
}
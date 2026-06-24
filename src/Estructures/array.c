#include <stdio.h>
#include <stdlib.h>

#include "Array.h"


// Crear arreglo con valores iniciales de 1 en 1
ARRAY *create_array(int amount)
{
    ARRAY *array = malloc(sizeof(ARRAY));


    if(array == NULL)
        return NULL;


    array->data = malloc(sizeof(int) * amount);


    if(array->data == NULL)
    {
        free(array);
        return NULL;
    }


    array->size = amount;


    // Asignar valores iniciales
    for(int i = 0; i < amount; i++)
    {
        array->data[i] = i + 1;
    }


    return array;
}



// Insertar en una posición específica
int insert_array(ARRAY *array, int index, int value)
{
    if(array == NULL)
        return 0;


    if(index < 0 || index >= array->size)
        return 0;


    array->data[index] = value;


    return 1;
}



// Buscar valor
int search_array(ARRAY *array, int value)
{
    if(array == NULL)
        return 0;


    for(int i = 0; i < array->size; i++)
    {
        if(array->data[i] == value)
            return 1;
    }


    return 0;
}



// Eliminar valor
int delete_array(ARRAY *array, int value)
{
    if(array == NULL)
        return 0;


    for(int i = 0; i < array->size; i++)
    {
        if(array->data[i] == value)
        {

            // Mover elementos hacia la izquierda
            for(int j = i; j < array->size - 1; j++)
            {
                array->data[j] = array->data[j + 1];
            }


            array->size--;

            return 1;
        }
    }


    return 0;
}



// Mostrar arreglo
void print_array(ARRAY *array)
{
    if(array == NULL)
        return;


    for(int i = 0; i < array->size; i++)
    {
        printf("%d ", array->data[i]);
    }


    printf("\n");
}



// Liberar memoria
void free_array(ARRAY *array)
{
    if(array == NULL)
        return;


    free(array->data);

    free(array);
}
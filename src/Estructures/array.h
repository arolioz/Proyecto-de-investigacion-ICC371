#ifndef ARRAY_H
#define ARRAY_H


typedef struct Array
{
    int *data;
    int size;

} ARRAY;


/* Crear arreglo dinámico */
ARRAY *create_array(int amount);


/* Operaciones */
int insert_array(ARRAY *array, int index, int value);

int search_array(ARRAY *array, int value);

int delete_array(ARRAY *array, int value);


/* Mostrar y liberar */
void print_array(ARRAY *array);

void free_array(ARRAY *array);


#endif
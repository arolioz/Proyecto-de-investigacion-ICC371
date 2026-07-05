#include <stdio.h>
#include <stdlib.h>
#include "Estructures/LinkedList.h"
#include "Estructures/hash_table.h"
#include "Estructures/Array.h"
#include "Estructures/Stack.h"
#include "Estructures/binary_tree.h"
#include "Estructures/Queue.h"

#include <time.h>
#include <windows.h>
#include <psapi.h>

double obtener_memoria_kb();

void menuEstructuras();


int main(void){
    //LINKED_LIST *lista = create_linkedList(25);


    //insertar_linkedList(lista,20);
    //insertar_linkedList(lista,40);
    //insertar_linkedList(lista,30);
    //insertar_linkedList(lista,10);

    //printf("(Posicion: %i)\n",buscar_linkedList(lista,20));

    //mostrar_linkedList(lista);
    //eliminar_linkedList(lista,40);
    //mostrar_linkedList(lista);
    
    //printf("\n");
    
    clock_t inicio, fin;
    double tiempoTotal;
    int estructura;
    int operacion;
    int cantidad;
    int cantidadElementos[] = {1000, 50000, 250000, 500000, 1000000};
    char *operaciones[] = {"Insercion", "Busqueda", "Eliminacion"};
    
    double memoriaInicial, memoriaFinal, memoriaUsada;

    do {

        menuEstructuras();
        scanf("%d", &estructura);
        system("cls");

        if (estructura == 7) {
            break;
        }

        do {
        printf("1. Insercion\n");
        printf("2. B%csqueda\n", 163);
        printf("3. Eliminacion\n");
        printf("Seleccione la operaci%cn:\n", 162);
        scanf("%d", &operacion);
        system("cls");

        } while (operacion < 1 || operacion > 3);

        do {
            printf("\nCantidad de elementos\n");
            printf("1. 1000\n");
            printf("2. 50000\n");
            printf("3. 250000\n");
            printf("4. 500000\n");
            printf("5. 1000000\n");
            scanf("%d", &cantidad);
            system("cls");

        } while (cantidad < 1 || cantidad > 5);


        switch (estructura)
        {
            case 1:
                printf("Arreglos\n");

                ARRAY *arreglo = create_array(cantidadElementos[cantidad - 1]);

                inicio = clock();
                memoriaInicial = obtener_memoria_kb();

                if (operacion == 1) {
                    
                    insert_array(arreglo, 2, 15);

                }
                if (operacion == 2) {
                    int index = search_array(arreglo, cantidadElementos[cantidad - 1]);
                    printf("El valor %d se encuentra en el índice: %d\n", cantidadElementos[cantidad - 1], index); 
                    
                } 
                if (operacion == 3) {
                    int result = delete_array(arreglo, 1);
                    if (result) {
                        printf("El valor 1 ha sido eliminado de la lista.\n");
                    } else {
                        printf("El valor 1 no se encuentra en la lista.\n");
                    }

                }
                fin = clock();
                memoriaFinal = obtener_memoria_kb();
                memoriaUsada = memoriaFinal - memoriaInicial;
                tiempoTotal = (double)(fin - inicio) / CLOCKS_PER_SEC;

                printf("\nOperacion: %s\n", operaciones[operacion - 1]);
                printf("Cantidad de elementos: %d\n", cantidadElementos[cantidad - 1]);
                printf("Tiempo de ejecucion: %.9f segundos\n", tiempoTotal);
                printf("Memoria usada: %.9f KB\n\n", memoriaUsada);
                printf("----------------------------------------\n");
                free_array(arreglo);
                break;
            case 2:
                printf("Listas entrelazadas\n");

                LINKED_LIST *list = create_linkedList(cantidadElementos[cantidad - 1]);

                inicio = clock();

                if (operacion == 1) {
                    insertar_linkedList(list, 15);
                }
                if (operacion == 2) {
                    int index = buscar_linkedList(list, cantidadElementos[cantidad - 1]);
            
                    printf("El valor %d se encuentra en el índice: %d\n",cantidadElementos[cantidad - 1], index); 
                } 
                if (operacion == 3) {
                    int result = eliminar_linkedList(list, 15);
                    if (result) {
                        printf("El valor 15 ha sido eliminado de la lista.\n");
                    } else {
                        printf("El valor 15 no se encuentra en la lista.\n");
                    }

                }
                fin = clock();
                tiempoTotal = (double)(fin - inicio) / CLOCKS_PER_SEC;

                printf("\nOperacion: %s\n", operaciones[operacion - 1]);
                printf("Cantidad de elementos: %d\n", cantidadElementos[cantidad - 1]);
                printf("Tiempo de ejecucion: %f segundos\n\n", tiempoTotal);
                printf("----------------------------------------\n");
                free_linkedList(list);
                break;
                
            case 3:
                printf("Tabla Hash\n");
                
                HASH_TABLE *lista = create_hash_table(cantidadElementos[cantidad - 1]);

                inicio = clock();

                if (operacion == 1) {
                    insert_hash(lista,cantidadElementos[cantidad - 1]);

                }
                if (operacion == 2) {
                    int index = search_hash(lista,cantidadElementos[cantidad - 1]);
            
                    printf("El valor %d se encuentra en el índice: %d\n",cantidadElementos[cantidad - 1], index); 
                     
                } 
                if (operacion == 3) {
                    int result = delete_hash(lista, 15);
                    if (result) {
                        printf("El valor 15 ha sido eliminado de la tabla hash.\n");
                    } else {
                        printf("El valor 15 no se encuentra en la tabla hash.\n");
                    }
                    
                }
                fin = clock();
                tiempoTotal = (double)(fin - inicio) / CLOCKS_PER_SEC;

                printf("\nOperacion: %s\n", operaciones[operacion - 1]);
                printf("Cantidad de elementos: %d\n", cantidadElementos[cantidad - 1]);
                printf("Tiempo de ejecucion: %.6f segundos\n\n", tiempoTotal);
                printf("----------------------------------------\n");
                free_hash(lista);
                break;
            case 4:
                printf("Arbol Binario de Busqueda (BST)\n");
                 
                BINARY_TREE *arbol = create_tree(cantidadElementos[cantidad - 1]);

                inicio = clock();
                memoriaInicial = obtener_memoria_kb();

                
                if (operacion == 1) {
                    insert_tree(arbol, cantidadElementos[cantidad - 1] + 1);
                    
                }
                if (operacion == 2) {
                    search_tree(arbol, 1);
                     
                } 
                if (operacion == 3) {
                    delete_tree(arbol, cantidadElementos[cantidad - 1]);
                    
                }

                fin = clock();
                tiempoTotal = (double)(fin - inicio) / CLOCKS_PER_SEC;

                memoriaFinal = obtener_memoria_kb();
                memoriaUsada = memoriaFinal - memoriaInicial;

                printf("\nOperacion: %s\n", operaciones[operacion - 1]);
                printf("Cantidad de elementos: %d\n", cantidadElementos[cantidad - 1]);
                printf("Tiempo de ejecucion: %f segundos\n\n", tiempoTotal);
                printf("Memoria usada: %.6f KB\n\n", memoriaUsada);
                printf("----------------------------------------\n");
                free_tree(arbol);
                break;          

            case 5:
                printf("Pila\n");
                
                STACK *pila = create_stack(cantidadElementos[cantidad - 1]);
                int value;
                inicio = clock();

                if (operacion == 1) {
                    push(pila, 17);
                }
                if (operacion == 2) {
                    peek(pila, &value);
                } 
                if (operacion == 3) {
                    pop(pila, &value);
                }

                fin = clock();
                tiempoTotal = (double)(fin - inicio) / CLOCKS_PER_SEC;

                printf("\nOperacion: %s\n", operaciones[operacion - 1]);
                printf("Cantidad de elementos: %d\n", cantidadElementos[cantidad - 1]);
                printf("Tiempo de ejecucion: %f segundos\n\n", tiempoTotal);
                printf("----------------------------------------\n");
                free_stack(pila);
                break;          

            case 6:
            {
                printf("Cola\n");
                
                QUEUE *cola = create_queue(cantidadElementos[cantidad - 1]);
                int value;
                inicio = clock();

                if (operacion == 1) {
                    enqueue(cola, 17);

                    
                }
                if (operacion == 2) {
                    peek_queue(cola, &value);
                     
                } 
                if (operacion == 3) {
                    dequeue(cola, &value);
                    
                }
                fin = clock();
                tiempoTotal = (double)(fin - inicio) / CLOCKS_PER_SEC;

                printf("\nOperacion: %s\n", operaciones[operacion - 1]);
                printf("Cantidad de elementos: %d\n", cantidadElementos[cantidad - 1]);
                printf("Tiempo de ejecucion: %f segundos\n\n", tiempoTotal);
                printf("----------------------------------------\n");
                free_queue(cola);
                break;  
            }
            case 7:
                printf("Saliendo del menu...\n");
                break;

        }

    }while (estructura != 7);

    return 0;

}

void crearArreglo(int *arreglo, int cantidad) {

    for (int i = 0; i < cantidad; i++)
    {
        arreglo[i] = rand() % cantidad;;
    }
    
}

void menuEstructuras() {
    printf("1. Arreglos\n");
        printf("2. Listas entrelazadas\n");
        printf("3. Tabla Hash\n");
        printf("4. Arbol Binario de Busqueda (BST)\n");
        printf("5. Pila\n");
        printf("6. Cola\n");
        printf("7. Salir\n");
        printf("Seleccione la estructura de datos: ");
}

double obtener_memoria_kb() {
    PROCESS_MEMORY_COUNTERS pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
    // Dividimos entre 1024 para convertir los Bytes del sistema a Kilobytes
    return (double)(pmc.WorkingSetSize / 1024); 
}
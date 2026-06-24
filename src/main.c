#include <stdio.h>
#include <stdlib.h>
#include "Estructures/LinkedList.h"
#include <time.h>


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
            printf("1. 1000\n");\
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
                break;
            case 2:
                printf("Listas entrelazadas\n");

                LINKED_LIST *list = create_linkedList(cantidadElementos[cantidad - 1]);

                inicio = clock();

                if (operacion == 1) {
                    insertar_linkedList(list, 15);
                }
                if (operacion == 2) {
                    int index = buscar_linkedList(list, rand() % cantidadElementos[cantidad - 1]);
            
                    printf("El valor %d se encuentra en el índice: %d\n", rand() % cantidadElementos[cantidad - 1], index); 
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
                break;
                
            case 3:
                printf("Tabla Hash\n");
                
                //LINKED_LIST *list = create_linkedList(cantidadElementos[cantidad - 1]);

                inicio = clock();

                if (operacion == 1) {
                    
                }
                if (operacion == 2) {
                     
                } 
                if (operacion == 3) {
                    
                }
                fin = clock();
                tiempoTotal = (double)(fin - inicio) / CLOCKS_PER_SEC;

                printf("\nOperacion: %s\n", operaciones[operacion - 1]);
                printf("Cantidad de elementos: %d\n", cantidadElementos[cantidad - 1]);
                printf("Tiempo de ejecucion: %f segundos\n\n", tiempoTotal);
                printf("----------------------------------------\n");

                break;
            case 4:
                printf("Arbol Binario de Busqueda (BST)\n");

                printf("Tabla Hash\n");
                
                //LINKED_LIST *list = create_linkedList(cantidadElementos[cantidad - 1]);

                inicio = clock();

                if (operacion == 1) {
                    
                }
                if (operacion == 2) {
                     
                } 
                if (operacion == 3) {
                    
                }
                fin = clock();
                tiempoTotal = (double)(fin - inicio) / CLOCKS_PER_SEC;

                printf("\nOperacion: %s\n", operaciones[operacion - 1]);
                printf("Cantidad de elementos: %d\n", cantidadElementos[cantidad - 1]);
                printf("Tiempo de ejecucion: %f segundos\n\n", tiempoTotal);
                printf("----------------------------------------\n");

                break;          

            case 5:
                printf("Pila\n");

                printf("Tabla Hash\n");
                
                //LINKED_LIST *list = create_linkedList(cantidadElementos[cantidad - 1]);

                inicio = clock();

                if (operacion == 1) {
                    
                }
                if (operacion == 2) {
                     
                } 
                if (operacion == 3) {
                    
                }
                fin = clock();
                tiempoTotal = (double)(fin - inicio) / CLOCKS_PER_SEC;

                printf("\nOperacion: %s\n", operaciones[operacion - 1]);
                printf("Cantidad de elementos: %d\n", cantidadElementos[cantidad - 1]);
                printf("Tiempo de ejecucion: %f segundos\n\n", tiempoTotal);
                printf("----------------------------------------\n");

                break;          

            case 6:
                printf("Cola\n");

                printf("Tabla Hash\n");
                
                //LINKED_LIST *list = create_linkedList(cantidadElementos[cantidad - 1]);

                inicio = clock();

                if (operacion == 1) {
                    
                }
                if (operacion == 2) {
                     
                } 
                if (operacion == 3) {
                    
                }
                fin = clock();
                tiempoTotal = (double)(fin - inicio) / CLOCKS_PER_SEC;

                printf("\nOperacion: %s\n", operaciones[operacion - 1]);
                printf("Cantidad de elementos: %d\n", cantidadElementos[cantidad - 1]);
                printf("Tiempo de ejecucion: %f segundos\n\n", tiempoTotal);
                printf("----------------------------------------\n");
                
                break;  

            case 7:
                printf("Saliendo del menu...\n");
                break;

        }

    }while (estructura < 1 || estructura > 7);

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

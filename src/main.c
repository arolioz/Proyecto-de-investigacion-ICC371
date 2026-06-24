#include <stdio.h>
#include "Estructures/LinkedList.h"
#include <time.h>


int main(void){
    LINKED_LIST *lista = create_linkedList(25);


    insertar_linkedList(lista,20);
    insertar_linkedList(lista,40);
    insertar_linkedList(lista,30);
    insertar_linkedList(lista,10);

    printf("(Posicion: %i)\n",buscar_linkedList(lista,20));

    mostrar_linkedList(lista);
    eliminar_linkedList(lista,40);
    mostrar_linkedList(lista);
    
    printf("\n");
    

    clock_t inicio, fin;
    double tiempoTotal;
    int estructura;
    int operacion;
    int cantidad;

    do {

        printf("1. Arreglos\n");
        printf("2. Listas entrelazadas\n");
        printf("3. Tabla Hash\n");
        printf("4. Arbol Binario de Busqueda (BST)\n");
        printf("5. Pila\n");
        printf("6. Cola\n");
        printf("7. Salir\n");
        printf("Seleccione la estructura de datos:\n");
        scanf("%d", &estructura);

    }while (estructura < 1 || estructura > 7);

    do {
        printf("1. Insercion\n");
        printf("2. B%csqueda\n", 163);
        printf("3. Eliminacion\n");
        printf("Seleccione la operaci%cn:\n", 162);
        scanf("%d", &operacion);

    } while (operacion < 1 || operacion > 3);

    inicio = clock();

    switch (estructura)
    {
        case 1:
            printf("Arreglos\n");
            break;
        case 2:
            printf("Listas entrelazadas\n");
            LINKED_LIST *list = create_linkedList(50000);

            if (operacion == 1) {
                insertar_linkedList(list, 15);

                break;
            }
            if (operacion == 2) {
                int index = buscar_linkedList(list, 15);
                if (index != -1) {
                    printf("El valor 15 se encuentra en el índice: %d\n", index);
                } else {
                    printf("El valor 15 no se encuentra en la lista.\n");
                }
                break;
            } 
            if (operacion == 3) {
                int result = eliminar_linkedList(list, 15);
                if (result) {
                    printf("El valor 15 ha sido eliminado de la lista.\n");
                } else {
                    printf("El valor 15 no se encuentra en la lista.\n");
                }
                break;
            }
            
        case 3:
            printf("Tabla Hash\n");
            break;
        case 4:
            printf("Arbol Binario de Busqueda (BST)\n");
            break;          

        case 5:
            printf("Pila\n");
            break;          

        case 6:
            printf("Cola\n");
            break;  

        case 7:
            printf("Saliendo del menu...\n");
            break;

    }

    //LINKED_LIST *list = create(5, 10);

    fin = clock();
    tiempoTotal = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %f segundos\n", tiempoTotal);

    return 0;

}

void crearArreglo(int *arreglo, int cantidad) {

    for (int i = 0; i < cantidad; i++)
    {
        arreglo[i] = rand() % cantidad;;
    }
    
}
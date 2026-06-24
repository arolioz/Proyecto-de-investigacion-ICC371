#include <stdio.h>
#include "Estructures/LinkedList.h"


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
    

}
#include <stdio.h>
#include "Estructures/LinkedList.h"


int main(void){
    int n;
    
    printf("N: ");
    scanf("%i",&n);

    LINKED_LIST *test = create(n);
    
    printf("%i\n", test->value);
}
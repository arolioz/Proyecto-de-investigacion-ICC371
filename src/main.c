#include <stdio.h>
#include "Estructures/LinkedList.h"


int main(void){
    LINKED_LIST *test = create(10);
    
    printf("%i\n", test->value);
}
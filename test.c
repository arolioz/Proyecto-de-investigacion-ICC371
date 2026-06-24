#include <stdio.h>
#include "src/Estructures/LinkedList.h"
#include "src/Estructures/stack.h"
#include <time.h>


int main(void){
    STACK *stack = create_stack(10);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    print_stack(stack);
    int *a;
    pop(stack,a);
    print_stack(stack);
    
    free_stack(stack);

    return 0;
}

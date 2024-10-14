#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Dominguez Lira Estefani Michalle
// Rodriguez Rodriguez Erick Tadeo
// Programa que crea una pila de elementos tipo int
//Inserta 4 elementos y eliminia 2 elementos

static void print_stack(const Stack *stack) {
    ListNode *node;
    int *data, i;

    fprintf(stdout, "Stack size is %d\n\n", stack_size(stack));

    i = 0;
    node = list_head(stack);

    while (node != NULL) {
        data = (int *)list_data(node);
        fprintf(stdout, "stack.node[%03d]=%03d, %p -> %p \n", i, *data, node, node->next);

        i++;
        node = list_next(node);
    }
    printf("\n");
}

//Inicializar pila con 10 elementos
void initialize_stack(Stack *stack) {
	int i;
    for (i = 1; i <= 10; i++) {
        int *data = (int *)malloc(sizeof(int));
        if (data != NULL) {
            *data = i * 10; 
            stack_push(stack, data);
        }
    }
}

//Insertar elementos
void add_elements(Stack *stack) {
	int i;
    for (i = 1; i <= 4; i++) {
        int *data = (int *)malloc(sizeof(int));
        if (data != NULL) {
            *data = i * 100;
            stack_push(stack, data);
            printf("Insertando %d...\n", *data);
            print_stack(stack);
        }
    }
}

//Revover elementos
void remove_elements(Stack *stack) {
	int i;
    for (i = 0; i < 2; i++) {
        int *data;
        if (stack_pop(stack, (void **)&data) == 0) {
            printf("Removiendo %d...\n", *data);
            free(data);
            print_stack(stack);
        } else {
            fprintf(stderr, "No se pudo eliminar el elemento (stack vacio)\n");
        }
    }
}

int main(int argc, char **argv) {
    Stack stack;

    stack_init(&stack, free);

    initialize_stack(&stack);
    print_stack(&stack);

    add_elements(&stack);

    remove_elements(&stack);

    //Destruir la pila
    fprintf(stdout, "Destruyendo la pila...\n");
    stack_destroy(&stack);

    return 0;
}


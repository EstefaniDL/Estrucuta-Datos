#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

// Dominguez Lira Estefani Michalle
// Rodriguez Rodriguez Erick Tadeo
// Programa que crea una lista doblemente ligada de 10 caracteres 
//Con 4 funciones para añadir y 4 para eliminar intercaladas

static void print_list(const DList *list) {
    DListNode *node;
    char *data;
    int i;

    fprintf(stdout, "List size is %d\n", dlist_size(list));

    i = 0;
    node = dlist_head(list);

    while (node != NULL) {
        data = (char *)dlist_data(node);
        fprintf(stdout, "list.node[%03d]=%c, %p <- %p -> %p\n", i, *data, node->prev, node, node->next);
        i++;
        node = dlist_next(node);
    }

    return;
}

int main(int argc, char **argv) {
    DList list;
    DListNode *node;

    char *data;
    int i;

    // Inicializar la lista doblemente ligada
    dlist_init(&list, free);

    // Crear la lista con 10 elementos
    char elements[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    for (i = 0; i < 10; i++) {
        if ((data = (char *)malloc(sizeof(char))) == NULL)
            return 1;

        *data = elements[i];

        // Insertar al final de la lista
        if (dlist_ins_next(&list, dlist_tail(&list), data) != 0)
            return 1;
    }

    print_list(&list);

    // Eliminar un nodo
    node = dlist_head(&list);
    for (i = 0; i < 6; i++) {
        node = dlist_next(node);
    }

    data = (char *)dlist_data(node);
    fprintf(stdout, "\nRemoviendo %c\n", *data);

    if (dlist_remove(&list, node, (void **)&data) != 0)
        return 1;

    print_list(&list);

    // Insertar un nuevo nodo en la cola
    fprintf(stdout, "\nInsertando 'X' en la cola\n");
    if ((data = (char *)malloc(sizeof(char))) == NULL)
        return 1;

    *data = 'X';
    if (dlist_ins_next(&list, dlist_tail(&list), data) != 0)
        return 1;

    print_list(&list);

    // Eliminar un nodo 
    fprintf(stdout, "\nRemoviendo posicion 1\n");
    if (dlist_remove(&list, dlist_next(dlist_head(&list)), (void **)&data) != 0)
        return 1;
    
    print_list(&list);

    // Eliminar la cabeza
    fprintf(stdout, "\nRemoviendo la cabeza\n");
    if (dlist_remove(&list, dlist_head(&list), (void **)&data) != 0)
        return 1;

    print_list(&list);

    // Insertar un nodo en la cabeza
    fprintf(stdout, "\nInsertando 'Y' en la cabeza\n");
    if ((data = (char *)malloc(sizeof(char))) == NULL)
        return 1;

    *data = 'Y';
    if (dlist_ins_prev(&list, dlist_head(&list), data) != 0)
        return 1;

    print_list(&list);

    // Eliminar el cuarto nodo
    fprintf(stdout, "\nRemoviendo posicion 3\n");
    node = dlist_head(&list);
    for (i = 0; i < 3; i++) {
        node = dlist_next(node);
    }

    if (dlist_remove(&list, node, (void **)&data) != 0)
        return 1;

    print_list(&list);

    // Insertar un nodo después del primero
    fprintf(stdout, "\nInsertando 'Z' \n");
    if ((data = (char *)malloc(sizeof(char))) == NULL)
        return 1;

    *data = 'Z';
    if (dlist_ins_next(&list, dlist_head(&list), data) != 0)
        return 1;

    print_list(&list);

    // Destruir la lista
    fprintf(stdout, "\nDestruyendo lista....\n");
    dlist_destroy(&list);

    return 0;
}


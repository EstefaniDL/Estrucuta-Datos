#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

// Dominguez Lira Estefani Michalle
// Rodriguez Rodriguez Erick Tadeo
// Programa que crea una lista circular con 10 elementos de tipo flotante
//Con 4 funciones para añadir y 4 para eliminar 

static void print_clist(const CList *list) {
    CListNode *node;
    float *data;
    int i = 0;

    printf("Circular List size: %d\n", clist_size(list));

    node = clist_head(list);
    printf("\n");
    for (i = 0; i < clist_size(list); i++) {
        data = (float *)clist_data(node);
        printf("clist.node[%03d]=%.2f, %p -> %p\n", i, *data, node, clist_next(node));
        node = clist_next(node);
    }
}

//Función para insertar elementos despues de la cabeza
void add_element_after_head(CList *list, float value) {
    float *data = (float *)malloc(sizeof(float));
    if (data == NULL) {
        printf("Error en la asignacion de memoria\n");
        exit(1);
    }
    *data = value;
    clist_ins_next(list, clist_head(list), data);
}

//Función para insertar en la cabeza
void add_element_at_head(CList *list, float value) {
    float *data = (float *)malloc(sizeof(float));
    if (data == NULL) {
        printf("Error en la asignacion de memoria\n");
        exit(1);
    }
    *data = value;
    clist_ins_next(list, NULL, data); 
}

//Funcion para agregar en la "cola" (antes de la cabeza)
void add_element_at_end(CList *list, float value) {
    CListNode *node = clist_head(list);
    while (clist_next(node) != clist_head(list)) {
        node = clist_next(node);
    }
    float *data = (float *)malloc(sizeof(float));
    if (data == NULL) {
        printf("Error en la asignacion de memoria\n");
        exit(1);
    }
    *data = value;
    clist_ins_next(list, node, data);
}

//Funcion para insertar elementos despues del tercer nodo
void add_element_after_third(CList *list, float value) {
	int i;
    CListNode *node = clist_head(list);
    for (i = 0; i < 2; i++) {
        node = clist_next(node);
    }
    float *data = (float *)malloc(sizeof(float));
    if (data == NULL) {
        printf("Error en la asignacion de memoria\n");
        exit(1);
    }
    *data = value;
    clist_ins_next(list, node, data);
}

//Función para remover la cabeza
void remove_head(CList *list) {
    float *data;
    clist_rem_next(list, NULL, (void **)&data);
    free(data);
}

//Función para remover despues de la cabeza
void remove_after_head(CList *list) {
    float *data;
    clist_rem_next(list, clist_head(list), (void **)&data);
    free(data);
}

//Funcion para remover en la "cola" (antes de la cabeza/ último elemento)
void remove_last(CList *list) {
    CListNode *node = clist_head(list);
    while (clist_next(clist_next(node)) != clist_head(list)) {
        node = clist_next(node);
    }
    float *data;
    clist_rem_next(list, node, (void **)&data);
    free(data);
}

//Función para remover desde el tercer nodo
void remove_third(CList *list) {
	int i;
    CListNode *node = clist_head(list);
    for (i = 0; i < 1; i++) {
        node = clist_next(node);
    }
    float *data;
    clist_rem_next(list, node, (void **)&data);
    free(data);
}

int main() {
    CList list;
    int i;

    //Inicializar lista circular
    clist_init(&list, free);

    //Insertar 10 elementos flotantes
    for (i = 0; i < 10; i++) {
        float *data = (float *)malloc(sizeof(float));
        if (data == NULL)
            return 1;
        *data = i + 0.5f;
        if (clist_ins_next(&list, NULL, data) != 0)
            return 1;
    }

    //Imprimir lista
    print_clist(&list);

    //Insertar 4 elementos
    add_element_at_head(&list, 125.32f);
    add_element_after_head(&list, 8.48f);
    add_element_at_end(&list, 9.27f);
    add_element_after_third(&list, 12.36f);

    //Insertar 4 elementos
    printf("\nInsertando...");
    printf("\nInsertar posicion 1");
    printf("\nInsertar posicion 2");
    printf("\nInsertar posicion 3");
    printf("\nInsertar (ultimo elemento / elemento antes de la cabeza)\n");
    print_clist(&list);

    //Remover 4 elementos
    remove_head(&list);
    remove_after_head(&list);
    remove_last(&list);
    remove_third(&list);

    //Imprimir lista
    printf("\nRemoviendo...");
    printf("\nRemover la cabeza");
    printf("\nRemover posicion 2");
    printf("\nRemover posicion 4");
    printf("\nRemover (ultimo elemento / elemento antes de la cabeza)\n");
    print_clist(&list);

    // Destroy the list
    clist_destroy(&list);
    printf("\nDestruyendo lista...");

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "list.h"
// Dominguez Lira Estefani Michalle
// Rodriguez Rodriguez Erick Tadeo
// Programa que crea una lista de 10 caracteres con 4 funciones para añadir y 4 para eliminar

static void print_list(const List *list) {
    ListNode *node;
    char *data;
    int i;

    fprintf(stdout, "List size is %d\n", list_size(list));

    i = 0;
    node = list_head(list);

    while (1) {
        data = list_data(node);
        fprintf(stdout, "list.node[%03d]=%c, %p -> %p \n", i, *data, node, node->next);
        i++;

        if (list_is_tail(node))
            break;
        else
            node = list_next(node);
    }
    return;
}

void llenar_lista_con_caracteres (List *list) {
    char *data;
    int i;
    const char caracteres[] = "JDNLSOETBG";
    for (i = 0; i < 10; i++) {
        if ((data = (char *)malloc(sizeof(char))) == NULL)
            exit(1);

        *data = caracteres[i];
        if (i == 0) {
            if (list_ins_next(list, NULL, data) != 0)
                exit(1);
        } else {
            if (list_ins_next(list, list_head(list), data) != 0)
                exit(1);
        }
    }
}

void insertar_en_cabeza(List *list, char valor) {
    char *data = (char *)malloc(sizeof(char));
    *data = valor;
    if (list_ins_next(list, NULL, data) != 0)
        exit(1);
}

void insertar_en_posicion(List *list, char valor, int posicion) {
	int i;
    char *data = (char *)malloc(sizeof(char));
    *data = valor;
    ListNode *node = list_head(list);
    
    for (i = 0; i < posicion - 1 && node != NULL; ++i) {
        node = list_next(node);
    }
    if (list_ins_next(list, node, data) != 0)
        exit(1);
}

void eliminar_en_cabeza(List *list) {
    char *data;
    if (list_rem_next(list, NULL, (void**)&data) != 0)
        exit(1);
    free(data);
}

void eliminar_en_posicion(List *list, int posicion) {
	int i;
	char *data;
    ListNode *node = list_head(list);

    for (i = 0; i < posicion - 1 && node != NULL; ++i) {
        node = list_next(node);
    }
    if (list_rem_next(list, node, (void**)&data) != 0)
        exit(1);
    free(data);
}

int main(int argc, char **argv) {
    List list;

    list_init(&list, free);
    llenar_lista_con_caracteres(&list);
    print_list(&list);

    fprintf(stdout, "\nInsertando 'A' en la cabeza\n");
    insertar_en_cabeza(&list, 'A');
    print_list(&list);

    fprintf(stdout, "\nInsertando 'W' en la posicion 5\n");
    insertar_en_posicion(&list, 'W', 5);
    print_list(&list);

    fprintf(stdout, "\nInsertando 'T' en la posicion 8\n");
    insertar_en_posicion(&list, 'T', 8);
    print_list(&list);

    fprintf(stdout, "\nInsertando 'M' en la cola\n");
    insertar_en_posicion(&list, 'M', 13);
    print_list(&list);

    fprintf(stdout, "\nEliminando el elemento de la cabeza\n");
    eliminar_en_cabeza(&list);
    print_list(&list);

    fprintf(stdout, "\nEliminando el elemento de la posicion 4\n");
    eliminar_en_posicion(&list, 4);
    print_list(&list);

    fprintf(stdout, "\nEliminando el elemento de la posicion 7\n");
    eliminar_en_posicion(&list, 7);
    print_list(&list);
    
    fprintf(stdout, "\nEliminando el elemento de la cola\n");
    eliminar_en_posicion(&list, 10);
    print_list(&list);

    fprintf(stdout, "\nDestruyendo la lista\n");
    list_destroy(&list);

    return 0;
}

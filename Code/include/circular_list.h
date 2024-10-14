// circular_list.h

#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

// Estructura de un nodo de la lista doblemente enlazada circular
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Funciones para manejar la lista
Node* create_node(int data);
void insert_end(Node** head, int data);
void display_list(Node* head);
void free_list(Node** head);

#endif // CIRCULAR_LIST_H

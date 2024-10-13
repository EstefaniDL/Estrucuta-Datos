#ifndef LIST_H
#define LIST_H

// Definicion del nodo
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Funciones para manejar la lista
Node* create_node(int data);
void insert_end(Node** head, int data);
void display_list(Node* head);
void free_list(Node* head);

#endif

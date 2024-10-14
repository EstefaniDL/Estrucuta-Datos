
#include <stdio.h>
#include <stdlib.h>
#include "circular_list.h"

// Dominguez Lira Estefani Michalle
// Rodriguez Rodriguez Erick Tadeo
// Programa que crea una lista doblemente circular

// Funcion para crear un nuevo nodo
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Error: no se pudo asignar memoria para el nodo\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

// Funcion para insertar un nodo al final de la lista
void insert_end(Node** head, int data) {
    Node* new_node = create_node(data);
    if (!new_node) return;

    if (*head == NULL) {
        *head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        Node* tail = (*head)->prev;
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = *head;
        (*head)->prev = new_node;
    }
}

// Funcion para mostrar la lista con los punteros
void display_list(Node* head) {
    if (head == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }

    Node* temp = head;
    printf("Lista circular doblemente enlazada:\n");
    do {
        printf("Nodo: %p | Data: %d | Next: %p | Prev: %p\n", 
               (void*)temp, temp->data, (void*)temp->next, (void*)temp->prev);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

// Funcion para liberar la memoria de la lista
void free_list(Node** head) {
    if (*head == NULL) return;

    Node* current = *head;
    Node* next_node;

    do {
        next_node = current->next;
        free(current);
        current = next_node;
    } while (current != *head);

    *head = NULL;
}

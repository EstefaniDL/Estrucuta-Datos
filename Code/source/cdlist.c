#include <stdio.h>
#include <stdlib.h>
#include "cdlist.h"

// Crear un nuevo nodo
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Error de memoria\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = new_node->prev = new_node;  // Apunta a si mismo, ya que es circular
    return new_node;
}

// Insertar un nodo al final de la lista
void insert_end(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;  // Si la lista está vacia, el nuevo nodo es el unico nodo
    } else {
        Node* last = (*head)->prev;  // Último nodo (anterior a la cabeza)
        last->next = new_node;       // Conectar último nodo con el nuevo nodo
        new_node->prev = last;
        new_node->next = *head;      // Conectar el nuevo nodo a la cabeza
        (*head)->prev = new_node;    // Conectar el head con el nuevo nodo
    }
}

// Mostrar los elementos de la lista
void display_list(Node* head) {
    if (head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Node* temp = head;
    printf("Lista doblemente enlazada circular: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);  // Sigue hasta que regrese a la cabeza
    printf("\n");
}

// Liberar memoria de la lista
void free_list(Node* head) {
    if (head == NULL) return;

    Node* current = head;
    do {
        Node* temp = current;
        current = current->next;
        free(temp);
    } while (current != head);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "list.h"

// Encolar (insertar) un elemento en la cola
int queue_enqueue(Queue *queue, const void *data) {
    return list_ins_next(queue, list_tail(queue), data);
}

// Desencolar (eliminar) un elemento de la cola
int queue_dequeue(Queue *queue, void **data) {
    // Debemos eliminar el elemento al frente (cabeza) de la lista
    return list_rem_next(queue, NULL, data);
}

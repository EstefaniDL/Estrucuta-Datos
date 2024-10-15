// Dominguez Lira Estefani Michalle
// Rodriguez Rodriguez Erick Tadeo
// Programa que crea una queve utilizando una cadena de caracteres

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "list.h"

int i;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <cadenas de texto>\n", argv[0]);
        return 1;
    }

    // Crear una cola
    Queue queue;
    queue_init(&queue, free);  // Inicializamos la cola y configuramos que se liberen las cadenas

    // Insertar cada argumento (cadena) en la cola
    for (i = 1; i < argc; i++) {
        char *str = strdup(argv[i]);  // Copiamos el string para almacenarlo en la cola
        if (queue_enqueue(&queue, str) != 0) {
            printf("Error al encolar\n");
            queue_destroy(&queue);
            return 1;
        }
    }

    // Mostrar el tamaño de la cola
    printf("Tamano de la cola: %d\n", queue_size(&queue));

    // Desencolar todos los elementos
    char *dequeued_str;
    while (queue_size(&queue) > 0) {
        if (queue_dequeue(&queue, (void **)&dequeued_str) == 0) {
            printf("Desencolado: %s\n", dequeued_str);
            free(dequeued_str);  // Liberamos la memoria del string
        }
    }

    // Destruir la cola
    queue_destroy(&queue);

    return 0;
}

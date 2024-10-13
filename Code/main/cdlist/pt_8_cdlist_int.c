#include <stdio.h>
#include <stdlib.h>
#include "cdlist.h"

int i;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Uso: %s <numeros enteros>\n", argv[0]);
        return 1;
    }

    Node* head = NULL;

    // Insertar cada argumento en la lista
    for (i = 1; i < argc; i++) 
	{
    int num = atoi(argv[i]);
    printf("Insertando: %d\n", num);  // Debug
    insert_end(&head, num);
}

    // Mostrar la lista
    display_list(head);

    // Liberar memoria
    free_list(head);

    return 0;
}

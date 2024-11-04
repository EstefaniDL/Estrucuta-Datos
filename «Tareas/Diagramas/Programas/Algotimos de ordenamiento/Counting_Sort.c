#include <stdio.h>
#include <stdlib.h>
#define MAX 199 // Rango de -99 a 99 porque sino mi cumpu explota
#define OFFSET 99  // Reajuste con respecto a los numeros negativos

// Dominguez Lira Estefani Michalle
// Rodriguez Rodriguez Erick Tadeo
// Algoritmo de ordenamiento Counting Sort

void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void countingSort(int arr[], int n) {
    int output[n];
    int count[MAX] = {0};

    //Revision de cada cuanto aparece un numero
    for (int i = 0; i < n; i++) {
        count[arr[i] + OFFSET]++;
    }
    printf("\nPaso 1 - Poner unos y ceros: \n\n");
    imprimirArray(count, MAX);

    //Sumar acumulativamente
    for (int i = 1; i < MAX; i++) {
        count[i] += count[i - 1];
    }
    printf("\nPaso 2 - Conteo acumulativo: \n\n");
    imprimirArray(count, MAX);

    //Ordenar lista
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] + OFFSET] - 1] = arr[i]; 
        count[arr[i] + OFFSET]--;
    }

    //Lista ordenada
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n;

    printf("Cantidad de elementos: ");
    scanf("%d", &n);
    
    int arr[n];

    printf("Elementos de (-99 a 99):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nLista ingresada:\n");
    imprimirArray(arr, n);

    countingSort(arr, n);

    printf("\nLista ordenada:\n");
    imprimirArray(arr, n);

    return 0;
}

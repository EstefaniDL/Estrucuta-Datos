#include <stdio.h>
#include <stdlib.h>

// Dominguez Lira Estefani Michalle
// Rodríguez Rodríguez Erick Tadeo
// Algoritmo de ordenamiento Quick Sort dinámico

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort_dynamic(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort_dynamic(arr, low, pi - 1);
        quickSort_dynamic(arr, pi + 1, high);
    }
}

int main() {
    int n;
    int *arr;

    printf("Ingrese el número de elementos: ");
    scanf("%d", &n);

    // Asignación de memoria para el arreglo dinámico
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error de asignación de memoria.\n");
        return 1;
    }

    printf("Ingrese los elementos:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    quickSort_dynamic(arr, 0, n - 1);

    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Liberar la memoria asignada al arreglo dinámico
    free(arr);

    return 0;
}

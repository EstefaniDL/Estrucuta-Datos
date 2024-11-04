#include <stdio.h>

// Dominguez Lira Estefani Michalle
// Rodriguez Rodriguez Erick Tadeo
// Algoritmo de ordenamiento Quick Sort estático

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

void quickSort_static(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort_static(arr, low, pi - 1);
        quickSort_static(arr, pi + 1, high);
    }
}

int main() {
    int arr[10]; // Tamaño estático
    int n;
    
    //Este numero se puede cambiar pero así lo dejamos :)
    printf("Ingrese el número de elementos (máx. 10): ");
    scanf("%d", &n);

    if (n > 10) {
        printf("Por favor ingrese un número menor o igual a 10.\n");
        return 1;
    }

    printf("Ingrese los elementos:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    quickSort_static(arr, 0, n - 1);

    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

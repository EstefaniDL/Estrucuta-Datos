#include <stdio.h>
// Dominguez Lira Estefani Michalle
// Rodriguez Rodriguez Erick Tadeo
// Programa que imprime matriz de la ultima pocision a la primera de derecha a izquierda

int main() {
    int matriz[3][4];
    int i,j;

    printf("Elementos: \n");
    for(i=2; i>=0; i--) {
        for(j=3; j>=0 ; j--) {
            printf("Elemento [%d][%d]: ",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
    printf("\n");
    
    for (i=0; i<3; i++) {
        for (j=0; j<4; j++) {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}

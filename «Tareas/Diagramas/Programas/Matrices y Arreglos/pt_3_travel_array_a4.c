#include <stdio.h>
// Dominguez Lira Estefani Michalle
// Rodriguez Rodriguez Erick Tadeo
// Z de arriba para abajo de izquierda a derecha

int main() 
{
    int matriz[6][6];
    int i,j;

    printf("Elementos:\n");
    for (j=0; j<6; j++) 
	{
        printf("[0][%d]: ",j);
        scanf("%d",&matriz[0][j]);
    }
    for (i=1; i<5; i++) 
	{
        printf("[%d][%d]: ",i,5-i);
        scanf("%d",&matriz[i][5-i]);
    }
    for (j=0; j<6; j++) 
	{
        printf("[5][%d]: ",j);
        scanf("%d",&matriz[5][j]);
    }
    printf("\n");

    for (j=0; j<6; j++) 
	{
        printf("%d ",matriz[0][j]);
    }
    printf("\n");

    for (i=1; i<5; i++) 
	{
        for (j=0; j<5-i; j++) 
		{
            printf("  ");
        }
        printf("%d\n",matriz[i][5-i]);
    }
    for (j=0; j<6; j++) 
	{
        printf("%d ",matriz[5][j]);
    }
    printf("\n");
    return 0;
}

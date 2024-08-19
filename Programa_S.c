#include <stdio.h>
// Dominguez Lira Estefani Michalle
// Rodriguez Rodriguez Erick Tadeo
//Imprime una matriz en forma de s

int main() 
{
    int matriz[6][4];
    int i,j;

    printf("Elementos:\n");
    for (i=0; i<6; i++) 
	{
        for (j=0; j<4; j++) 
		{
            printf("[%d][%d]: ",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
    printf("\n");

    for (i=0; i<6; i++) 
	{
        if (i%2==0) 
		{ 
            for (j=0; j<4; j++) 
			{
                printf("%d",matriz[i][j]);
            }
        } else 
		{
            for (j=3; j>=0; j--) 
			{
                printf("%d ", matriz[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}

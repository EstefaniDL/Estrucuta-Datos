#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Dominguez Lira Estefani Michalle
// Rodriguez Rodriguez Erick Tadeo
// Pide el numero de cuenta y luego imprime cada numero la misma cantidad de veces 

int main() {
    char cuenta[9];
    int i, j;
    int tam, num;
    
    printf("Account number: ");	
    scanf("%s",cuenta);
    tam=strlen(cuenta);
	int **mat=(int**)malloc(tam*sizeof(int*));
    for (i=0; i<tam; i++) 
	{
    	num=cuenta[i]-'0';
        if (num==0) 
		{
            mat[i]=NULL;
        } 
		else 
		{
            mat[i]=(int *)malloc(num*sizeof(int));
            for (j=0; j<num; j++) 
			{
                mat[i][j]=num;
            }
        }
    }

    printf("\n");
    for (i=0; i<tam; i++) 
	{
        if (mat[i]==NULL)
		{
            printf("|NULL|\n");
        }
		else 
		{
            for(j=0; j<(cuenta[i]-'0'); j++) 
			{
                printf(" %d |",mat[i][j]);
            }
            printf("\n");
        }
    }
    for (i=0; i<tam; i++) 
	{
        if (mat[i]!=NULL)
		{
            free(mat[i]);
        }
    }
    free(mat);
    return 0;
}

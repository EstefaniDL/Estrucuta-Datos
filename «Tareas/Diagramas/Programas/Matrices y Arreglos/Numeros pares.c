#include <stdio.h>
#include <stdlib.h>
#define c 10
// Dominguez Lira Estefani Michalle
// Rodriguez Rodriguez Erick Tadeo
// Imprime números pares desde el 20 hasta el 2
// Cambia por -1 según el último número del número de cuenta

int main() 
{
    int i,un;
    int *num=(int*)malloc(c*sizeof(int));
    int numcu;

	printf("Lista de pares en orden inverso:\n\n");
    for(i=0; i<c; i++) 
	{
        num[i]=(i+1)*2;
    }
    for(i=c-1; i>=0; i--) 
	{
        printf(" %d |",num[i]);
    }
    
    printf("\n\nAccount number: ");
    scanf("%d",&numcu);
    
    un=numcu%10;
    if(un>=0 && un<10)
    {
    	num[un]=-1;
	}
    printf("\nLista con -1:\n\n");
    for (i=0; i<10; i++) {
        printf(" %d |",num[i]);
    }
    free(num);
    return 0;
}

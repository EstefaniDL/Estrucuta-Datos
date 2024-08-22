#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Dominguez Lira Estefani Michalle
// Rodriguez Rodriguez Erick Tadeo
// Matriz de tamaño nx3 que saca promedio de edad y promedio de calificacion
// Imprime los nombres ingresados en orden inverso

int main() 
{
    int c;
    int i;
    char nombre[25];
    int edad, cal;
    int pe=0;
    int pc=0;
    float promed, promcal;
    
    printf("Cantidad de alumnos: ");
    scanf("%d",&c);

    char **alum=(char**)malloc(c*sizeof(char*));
    for (i=0; i<c; i++) 
	{
        alum[i]=(char*)malloc(25*sizeof(char)+10*sizeof(char));
    }

    for (i=0; i<c; i++) {
        printf("Nombre [%d]: ",i+1);
        scanf("%s",&nombre);
        printf("Edad [%d]: ",i+1);
        scanf("%d",&edad);
        printf("Calificaci%cn [%d]: ",162,i+1);
        scanf("%d",&cal);
        snprintf(alum[i],25,"%s",nombre);
        snprintf(alum[i]+25,5,"%d",edad);
        snprintf(alum[i]+30,5,"%d",cal);
        pe+=edad;
        pc+=cal;
    }

    promed=(float)pe/c;
    promcal=(float)pc/c;
    printf("\nPromedio de edad: %.2f\n",promed);
    printf("Promedio de calificaci%cn: %.2f\n",162,promcal);
    printf("\nNombres en orden inverso:\n\n");
    for (i=c-1; i>=0; i--) 
	{
        printf("%s\n",alum[i]);
    }

    for (i=0; i<c; i++) 
	{
        free(alum[i]);
    }
    free(alum);
    return 0;
}

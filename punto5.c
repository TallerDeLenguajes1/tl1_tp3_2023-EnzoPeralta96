#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

int main(){

    int cantNombres;
    char arregloAux[MAX];

    printf("Ingrese la cantidad de nombres que quiere guardar:");
        fflush(stdin);
        scanf("%d",&cantNombres);
    
    char **nombres=malloc(sizeof(char *)*cantNombres);

    for (int i = 0; i < cantNombres; i++)
    {
        printf("Nombre nro %d:",i+1);
        fflush(stdin);
        gets(arregloAux);
        nombres[i]=malloc(sizeof(char)*(strlen(arregloAux)+1));
        strcpy(nombres[i],arregloAux);
    }

    printf("Los nombres ingresados son:\n");
    for (int i = 0; i < cantNombres; i++)
    {
        puts(nombres[i]);
        free(nombres[i]);
    }
    free(nombres);

    return 0;
}

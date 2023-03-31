#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define TAMA 2

void main(){
    char * arregloDePunteros[TAMA];
    char arregloAuxiliar[MAX];

    for (int i = 0; i < TAMA; i++)
    {
        printf("Nombre nro:%d:",i+1);
        gets(arregloAuxiliar);
        arregloDePunteros[i]=malloc((strlen(arregloAuxiliar)+1)*sizeof(char));
        strcpy(arregloDePunteros[i],arregloAuxiliar);
    }
    printf("Los nombres cargados en el arreglo de punteros a char son:\n");
    for (int i = 0; i < TAMA; i++)
    {
        puts(arregloDePunteros[i]);
        free(arregloDePunteros[i]);
    }
    
}
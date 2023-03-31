#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(){
    int produccion[5][12];// i= años j=meses
    int promedio[5], aux=0, producionMax=0, produccionMin=50000, mesMax, mesMin, yearMax, yearMin;
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            produccion[i][j]=rand()%40001 + 10000;
          // produccion[i][j]=rand()%100 + 1;
            aux=aux+produccion[i][j];
            if (produccion[i][j]>producionMax)
            {
                producionMax=produccion[i][j];
                mesMax=j+1;
                yearMax=i+1;
            }
            if (produccion[i][j]<produccionMin)
            {
                produccionMin=produccion[i][j];
                mesMin=j+1;
                yearMin=i+1;
            }
            
            
        }
        promedio[i]=(aux/12);
        aux=0;
    }
    printf("MatrizProduccion:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Year:%d\n",i+1);
        for (int j = 0; j < 12; j++)
        {   
            printf("%d ",produccion[i][j]);
        }
        printf("\n");
        printf("Promedio year:%d = %d\n",1+i,promedio[i]);
        printf("\n");
    }
    printf("La mayor produccion fue de:%d || Year:%d - Mes:%d\n",producionMax,yearMax,mesMax);
    printf("La menor produccion fue de:%d || Year:%d - Mes:%d\n",produccionMin,yearMin,mesMin);

}
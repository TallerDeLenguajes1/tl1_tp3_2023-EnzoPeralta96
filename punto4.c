#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define MAX 50

char *tiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto
{
    int ProductoID;
    int cantidad;
    char *TipoProducto;
    float PrecioUnitario;
}typedef Producto;

struct Cliente
{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
}typedef Cliente;

void cargarClientes(Cliente *puntCliente, int cantidad);
float costoProducto(Producto *puntProducto, int cantProductosPedidos);
void mostrarPedidos(Cliente *puntCliente, int cantidad);
void liberarMemoria(Cliente *puntCliente, int cantidad);

int main(){
    int cantidadClientes;
    int bandera=0;
    Cliente *Listado;

    while (bandera==0)
    {
        printf("Ingrese la cantidad de clientes visitados en el d%ca de hoy:",139);
            fflush(stdin);
            scanf("%d",&cantidadClientes);
        
        if (cantidadClientes<=5)
        {
            Listado=malloc(sizeof(Cliente)*cantidadClientes);
            bandera=1;
        }else
        {
            printf("La cantidad de clientes no puede ser mayor a 5\n");
        }
    }
    
    cargarClientes(Listado,cantidadClientes);
    mostrarPedidos(Listado,cantidadClientes);
    liberarMemoria(Listado,cantidadClientes);

    return 0;
}

void cargarClientes( Cliente *puntCliente, int cantidad){
    int tipoAux;
    char nombreAux[MAX];
    srand(time(NULL));

    printf("**********Cargar pedidos**********\n");
    for (int i = 0; i < cantidad; i++)
    {
        puntCliente->ClienteID=i+1;
        printf("----- Cliente ID:%d -----\n",puntCliente->ClienteID);

        puts("Nombre:");
            fflush(stdin);
            gets(nombreAux);
            puntCliente->NombreCliente=malloc(sizeof(char)*(strlen(nombreAux)+1));
            strcpy(puntCliente->NombreCliente,nombreAux);
        
        puntCliente->CantidadProductosAPedir=rand()%5+1;
            printf("Cantidad de productos a pedir:%d\n",puntCliente->CantidadProductosAPedir);

        puntCliente->Productos=malloc(puntCliente->CantidadProductosAPedir*sizeof(Producto));
            for (int j = 0; j < puntCliente->CantidadProductosAPedir; j++)
            {
                puntCliente->Productos[j].ProductoID=j+1;
                puntCliente->Productos[j].cantidad=rand()%10+1;
                    //printf("Producto ID:%d -----> Cantidad:%d \n",puntCliente->Productos[j].ProductoID,puntCliente->Productos[j].cantidad);

                tipoAux=rand()%5;
                puntCliente->Productos[j].TipoProducto=tiposProductos[tipoAux];
                puntCliente->Productos[j].PrecioUnitario=(float)(rand()%10000 + 10)/100;
                   // printf("Tipo producto:%s -----> Precio unitario:%.2f\n",puntCliente->Productos[j].TipoProducto,puntCliente->Productos[j].PrecioUnitario);
            }
            printf("\n");
            puntCliente++;
    }
    
}

float costoProducto(Producto *puntProducto, int cantProdPedidos){
  float costoTotal=0, costoXprod;
  for (int j = 0; j < cantProdPedidos; j++)
  {
    costoXprod = puntProducto->cantidad*puntProducto->PrecioUnitario;
    costoTotal = costoTotal + costoXprod;
    puntProducto++;
  }
  return costoTotal;
}

void mostrarPedidos(Cliente *puntCliente, int cantidad){

    puts("\n**********LISTADO DE CLIENTES**********\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("##### Cliente ID:%d || Nombre:%s #####\n",puntCliente->ClienteID,puntCliente->NombreCliente);
        printf("Cantidad de productos a pedir:%d\n",puntCliente->CantidadProductosAPedir);
        for (int j = 0; j < puntCliente->CantidadProductosAPedir; j++)
        {
            printf("Producto ID:%d ------> Cantidad:%d \n",puntCliente->Productos[j].ProductoID,puntCliente->Productos[j].cantidad);
            printf("Tipo producto:%s ------> Precio unitario:%.2f\n",puntCliente->Productos[j].TipoProducto,puntCliente->Productos[j].PrecioUnitario);
            printf("\n");
        }
        printf("Costo total----------->%c%.2f\n",36,costoProducto(puntCliente->Productos,puntCliente->CantidadProductosAPedir));
        puntCliente++;
        puts("\n");
    }  
}

void liberarMemoria(Cliente *puntCliente, int cantidad){

    for (int i = 0; i < cantidad; i++)
    {
        free(puntCliente->NombreCliente);
        free(puntCliente->Productos);
        puntCliente++;
    }
    free(puntCliente);
}
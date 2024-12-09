/*
Escribir un programa modular en C, que permita listar los datos de los productos que se encuentran en el archivo productos.dat.
La estructura de los registros es la siguiente:

typedef struct{
	int codigo;
	char descripcion[30];
	float cantidad;
}t_regProducto;
El archivo sólo se puede leer una vez.
Informar al final del listado, el total de Productos en Stock.
*/

#include <stdio.h>


typedef struct{
    int codigo;
    char descripcion[30];
    float cantidad;
}t_regProducto;

void listar_productos(FILE *arProductos){
    t_regProducto reg;

    float total_stock = 0;
    int contador_productos = 0;

    printf("Listado de Productos:\n");
    printf("Código\tDescripción\t\tCantidad\n");
    printf("-------------------------------------------\n");

    //Leer el archivo producto por producto
    while(fread(&reg, sizeof(t_regProducto), 1, arProductos) == 1){
        printf("%i\t%-20s\t%.2f\n", reg.codigo, reg.descripcion, reg.cantidad);
        total_stock += reg.cantidad;
        contador_productos++;
    } 

    //Informamos el total de stock.
    printf("-----------------------------\n");
    printf("Total de productos en stock: %.2f\n", total_stock);
    printf("Cantidad de productos: %i\n", contador_productos);

}

int main(void){
    FILE *arProductos;
    arProductos = fopen("productos.dat", "rb");

    if(arProductos == NULL){
        printf("No se pudo abrir el archivo");
    }else{
        listar_productos(arProductos);
    }

    fclose(arProductos);

    return 0;
}
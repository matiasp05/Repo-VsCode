/*
Escribir un programa modular en C, que solicite el ingreso de un código de producto, y luego muestre los datos asociados al mismo, que se encuentran en el archivo productos.dat que está debajo.
Si el código de producto no existe, debe mostrarse el mensaje "Código de Producto Inexistente".
El programa debe continuar solicitando el ingreso de códigos de próducto hasta que se ingrese 0.

La estructura de los registros es la siguiente:

typedef struct{
                int codigo;
                char descripcion[30];
                float cantidad;
}t_regProducto;
*/

#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int codigo;
    char descripcion[30];
    float cantidad;
}t_regProducto;

void buscar_codigo(int codigo_buscado, t_regProducto *producto){
    FILE *Productos;

    t_regProducto temp;
    
    bool encontrado = false;
    
    Productos = fopen("productos.dat", "rb");
    if(Productos == NULL){
        printf("No se pudo abrir el archivo");
    }
}
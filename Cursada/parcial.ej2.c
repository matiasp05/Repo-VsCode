/*
Desarrollar una funcion en C que reciba como parametros un vector de tipo Tvector
 ya cargado con datos que se encuentren en orden ascendentemente, su maximo logico 
 y un numero entero que debe ser intercalado en dicho vector de modo que este siga ordenado.
 Se espera que la funcion devuelva al modulo invocante true si pudo realizar lo solicitado y false si no pudo hacerlo.
  Tanto el vector como el maximo logico actualizados deben devolverse sobre los parametros recibidos.
  Escribir un programa que invoque dicha funcion. 
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 200
typedef int Tvector[MAX];

bool intercalar_numero(Tvector vector, int num_intercalar, int *largo){
    bool intercalado;
    if(*largo >= MAX){
        //El vector esta lleno.
        intercalado = false;
    } else {
        int i;
        i = *largo - 1;
        //Movemos los numeros mayores un lugar a la derecha.
        while(i>=0 && vector[i]>num_intercalar){
            vector[i+1] = vector[i];
            i--;
        }
        vector[i+1] = num_intercalar;
        (*largo)++;
        intercalado = true;
    }
    return intercalado;
}

int main(void){
    Tvector vector = {1, 3, 5, 7, 9};
    bool encontrado;
    int num_intercalar;
    int largo;
    largo = 5;
    int i;

    printf("Ingrese el numero a intercalar: ");
    scanf("%i", &num_intercalar);
    printf("-- Vector original --\n");
    for(i=0;i<largo;i++){
        printf("%i\t", vector[i]);
    }
    printf("\n");

    encontrado = intercalar_numero(vector, num_intercalar, &largo);
    if(encontrado){
        printf("El vector se ha actualizado correctamente.\n");
        printf("-- Vector actualizado --\n");
        for(i=0;i<largo;i++){
            printf("%i\t", vector[i]);
        }
        printf("\n");
    } else {
        printf("No se pudo intercalar el numero.");
    }
    return 0;
}
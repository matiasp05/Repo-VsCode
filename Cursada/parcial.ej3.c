/*
Desarrolar una funcion que reciba como parametros una matriz de tipo Tmatriz ya cargada sus maximos logicos 
(de filas y de columnas) y un numero entero, que devuelva al modulo invocante los siguientes valores.
La cant. de veces que el numero recibido por parametro esta presente en la matriz.
La cant. de elementos en la matriz que son mayores al numero recibido.
*/

#include <stdio.h>

#define CANTCOLS 30
#define CANTFILAS 20
typedef int Tmatriz[CANTFILAS][CANTCOLS];

void recorrer_funcion(Tmatriz matriz, int filas, int columnas, int numero, int *cant_veces_presente, int *numeros_mayores){
    int i, j;
    *cant_veces_presente = 0;
    *numeros_mayores = 0;
    for(i=0; i<filas; i++){
        for(j=0; j<columnas; j++){
            if(numero == matriz[i][j]){
                (*cant_veces_presente)++;
            }
            if(numero < matriz[i][j]){
                (*numeros_mayores)++;
            }
        }
    }
}

int main(void){
    Tmatriz matriz ={ {0,3,4}, {5,2,7}, {7,4,1} };
    int filas = 3, columnas = 3;
    int numero = 4;
    int cant_veces_presente, numeros_mayores;

    recorrer_funcion(matriz, filas, columnas, numero, &cant_veces_presente, &numeros_mayores);
    printf("El numero %i se repite %i veces y en la matriz se hayan %i elementos mayores.", numero, cant_veces_presente, numeros_mayores);
    
}
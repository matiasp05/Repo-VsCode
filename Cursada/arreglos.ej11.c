/*
 Escribir un subprograma que dada una matriz de números reales, de n x m,
devuelva un vector que en cada posición i almacene el elemento mínimo de cada fila i de la matriz.
*/

#include <stdio.h>
#define MAX_FIL 100
#define MAX_COL 100

void cargar_matriz(float matriz[][MAX_COL], int n, int m){
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("Ingrese el numero en la posicion [%i][%i]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }  
}

void minimo_fila(float matriz[][MAX_COL], int filas, int columnas, float minimos[]){
    int i,j;
    for(i=0;i<filas;i++){
        float minimo = matriz[i][0];
        for(j=0;j<columnas;j++){
            if(matriz[i][j] < minimo){
                minimo=matriz[i][j];
            }
            
        }
        minimos[i] = minimo;
    }
}

void imprimir_matriz(float matriz[][MAX_COL], int filas, int columnas){
    int i, j;
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            printf("%f\t", matriz[i][j]);
        }
        printf("\n"); 
    }
}

void imprimir_vector(float minimos[], int filas){
    int i;
    for(i=0;i<filas;i++){
        printf("%f\t", minimos[i]);
    }
}

int main(void){
    int filas, columnas;
    float matriz[MAX_FIL][MAX_COL];
    float minimos[MAX_FIL];
    
    printf("Ingresar numero de filas: ");
    scanf("%i", &filas);
    printf("Ingresar numero de columnas: ");
    scanf("%i", &columnas); 
    
    //Cargamos la matriz y la imprimimos.
    cargar_matriz(matriz, filas, columnas);
    printf("-- Matriz --\n");
    imprimir_matriz(matriz, filas, columnas);   
    
    //Sacamos su minimo en cada fila.
    minimo_fila(matriz, filas, columnas, minimos);
    
    //Imprimimos el vector.
    printf("-- Vector con minimos de cada fila. --\n");
    imprimir_vector(minimos, filas);

    return 0;
}
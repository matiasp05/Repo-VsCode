/*
Escribir un programa que cargue 2 (dos) matrices y sus dimensiones, las
multiplique en caso de ser posible o devuelva una señal si la operación no
puede realizarse. 
*/

#include <stdio.h>
#define MAX_FIL 100
#define MAX_COL 100

void cargar_matriz(int matriz[][MAX_COL], int filas, int columnas){
    int i,j;
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            printf("Ingrese el numero en la posicion (filas|columnas) [%i][%i]: ", i+1,j+1);
            scanf("%i", &matriz[i][j]);
        }
    }
}

void imprimir_matriz(int matriz[][MAX_COL], int filas, int columnas){
    int i,j;
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            printf("%i\t", matriz[i][j]);
        }
        printf("\n");
    }
        
}

int verificar_multiplicacion(int columnasA, int filasB) { 
    return columnasA == filasB;
}

void multiplicar_matrices(int matrizA[][MAX_COL], int filasA, int columnasA, int matrizB[][MAX_COL], int filasB, int columnasB, int matrizC[][MAX_COL]){
    int i,j,k;
    for(i=0;i<filasA;i++){
        for(j=0;j<columnasB;j++){
            matrizC[i][j] = 0;
            for(k=0;k<columnasA;k++){
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

int main(void){
    int filasA, filasB, columnasA, columnasB;
    int matrizA[MAX_FIL][MAX_COL], matrizB[MAX_FIL][MAX_COL], matrizC[MAX_FIL][MAX_COL];

    //Cargar la primera matriz.
    printf("Ingrese la Cant. Filas de la Matriz A: ");
    scanf("%i", &filasA);
    printf("Ingrese la Cant. Columnas de la Matriz A: ");
    scanf("%i", &columnasA);
    cargar_matriz(matrizA, filasA, columnasA);

    //Cargar segunda matriz.
    printf("Ingrese la Cant. Filas de la Matriz B: ");
    scanf("%i", &filasB);
    printf("Ingrese la Cant. Columnas de la Matriz B: ");
    scanf("%i", &columnasB);
    cargar_matriz(matrizB, filasB, columnasB);   
    
    printf("-- Matriz A --\n");
    imprimir_matriz(matrizA, filasA, columnasA);
    
    
    printf("-- Matriz B --\n");
    imprimir_matriz(matrizB, filasB, columnasB);
    

    //verificar multiplicacion
    if(verificar_multiplicacion(columnasA, filasB)){
        multiplicar_matrices(matrizA, filasA, columnasA, matrizB, filasB, columnasB, matrizC);
        printf("-- Matriz C --\n");
        imprimir_matriz(matrizC, filasA, columnasB);
    } else {
        printf("No es posible multiplicar estas matrices.");
    }
    return 0;
}
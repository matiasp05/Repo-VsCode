/*
Escribir una función, que reciba como primer parámetro un arreglo unidimensional (vector) de valores enteros y como segundo parámetro, la cantidad de valores a recorrer (ML) ó la última posición en el arreglo;
y devuelva el valor más alto que hay en el arreglo.

Suponga que el arreglo como máximo podrá almacenar hasta 10 valores.

Declare un tipo y máximo físico adecuado.

Para probar su función, incluya los siguientes casos de prueba, con la correspondiente invocación, e imprima lo que devuelve la función.

vec_1 = {8, -4, 7, 8, 0}
vec_2 = { -4, -7, -10}
vec_3 = { 425, -70, 500, 2, 43, 12, -1}

*/

#include <stdio.h>

#define MF 10

typedef int vector[MF];

int maximo_valor(vector v, int ML){
    int max = v[0];

    for(int i=1; i<ML; i++){
        if(v[i] > max){
            max = v[i];
        }
    }

    return max;
}

int main(void){
    vector vec_1 = {8, -4, 7, 8, 0};
    vector vec_2 = { -4, -7, -10};
    vector vec_3 = { 425, -70, 500, 2, 43, 12, -1};

    printf("El valor mas alto del vector 1 es: %i.\n", maximo_valor(vec_1, 5));
    printf("El valor mas alto del vector 2 es: %i.\n", maximo_valor(vec_2, 3));
    printf("El valor mas alto del vector 3 es: %i.\n", maximo_valor(vec_3, 7));

    return 0;

}
/*
Implementar una función la cual recibe un vector junto a su máximo lógico,
y retorne el vector con sus elementos en orden inverso.

Invocar dicha desde el main.

Ejemplo
original -> [1,2,3,4]
invertido -> [4,3,2,1]
*/

#include <stdio.h>
#define MF 8

typedef int Vector[MF];

void invertir_vector(int vec[], int ML){
    int i, aux;
    for(i=0;i<ML/2;i++){
        aux = vec[i];
        vec[i] = vec[ML-1-i];
        vec[ML-1-i] = aux;
    }
}

int main(void){
    Vector vec = {1,3,4,5,6,8};
    int ML = 6;

    printf("\nVector Original.\n");
    for(int i=0;i<ML;i++){
        printf("%i\t", vec[i]);
    }
    
    invertir_vector(vec, ML);

    printf("\nVector Invertido.\n");
    for(int i=0;i<ML;i++){
        printf("%i\t", vec[i]);
    }

    return 0;
}
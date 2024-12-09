/*
Un pastor cuenta sus ovejas. Le sobra siempre una si las cuenta de la
siguiente forma: de 3 en 3, de 5 en 5, de 6 en 6 o de 9 en 9. En cambio si
las cuenta de 7 en 7 no le sobra ninguna. Se pide escribir un programa que
le permita obtener ese valor, sabiendo que el número de ovejas no supera
el millar. 
*/

#include <stdio.h>
#define MILLAR 1000
void contador_ovejas(int vector[], int *ovejas){
    int i=0;
    for(*ovejas=1;*ovejas<MILLAR;(*ovejas)++){
        if(*ovejas % 3 == 1 && *ovejas % 5 == 1 && *ovejas % 6 == 1 && *ovejas % 9 == 1 && *ovejas % 7 == 0){
            vector[i] = *ovejas;
            i++;
        }
    }
}

int main(void){
    int ovejas;
    int vector[MILLAR]; 
    contador_ovejas(vector, &ovejas);

    printf("La cantidad de ovejas que se cuentan son: %i", vector[0]);
    return 0;
}
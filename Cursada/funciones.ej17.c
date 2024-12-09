/*
Escribir un programa que determine el máximo común divisor entre dos números. 
*/

#include <stdio.h>



void maximo_comun_divisor(int num1, int num2, int *divisor){
    if(num1<num2){
        *divisor = num1;
    } else {
        *divisor = num2;
    }

    if(num1 % *divisor != 0 || num2 % *divisor != 0){
        *divisor = 1;
    }
}

int main(void){
    int num1, num2, divisor;


    printf("Maximo comun divisor.\n");
    printf("Ingrese el primer numero: ");
    scanf("%i", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%i", &num2);

    maximo_comun_divisor(num1, num2, &divisor);

    printf("El maximo comun divisor entre %i y %i es: %i", num1, num2, divisor);

    return 0;
}
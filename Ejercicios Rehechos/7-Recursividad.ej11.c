/*
 Desarrollar un programa que solicite al usuario el ingreso de 2 números A y
B y calcule la potencia de A elevado a la B de forma recursiva.
*/

#include <stdio.h>

int calcular_potencia(int a, int b){
    if(b==1){
        return a;
    }
    if(b==0){
        return 1;
    }

    return a * calcular_potencia(a, b-1);
}

int main(void){
    int a, b;

    printf("Ingrese el numero que desea elevar: ");
    scanf("%i", &a);

    printf("Ingrese a que desea elevarlo: ");
    scanf("%i", &b);

    int potencia = calcular_potencia(a, b);
    printf("El resultado de elevar %i a la %i es: %i", a, b, potencia);

    return 0;
}
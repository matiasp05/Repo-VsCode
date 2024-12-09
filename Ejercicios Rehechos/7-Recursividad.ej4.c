/*
Desarrollar un programa que calcule y muestre por pantalla la división de 2
números mediante restas sucesivas en forma recursiva. Ambos números deben
ser ingresados por el usuario
*/

#include <stdio.h>

int res_sucesivas(int divisor, int dividendo){
    if(dividendo<divisor){
        return 0;
    }else{
        return 1 + res_sucesivas(divisor, dividendo - divisor);
    }
}

int main(void){
    int divisor, dividendo;

    printf("Ingrese el dividendo: ");
    scanf("%i", &dividendo);

    printf("Ingrese el divisor: ");
    scanf("%i", &divisor);

    int resultado = res_sucesivas(divisor, dividendo);

    printf("El resultado de %i dividido %i  es: %i.\n", dividendo, divisor, resultado);

    return 0;
}
/*
Escribir un programa que descomponga a un número en sus factores primos. 
*/

#include <stdio.h>

// Función para descomponer un número en factores primos
void descomponer_factores_primos(int num) {
    printf("Los factores primos de %d son: ", num);

    // Descomposición por 2
    while (num % 2 == 0) {
        printf("%d ", 2);
        num /= 2;
    }

    // Descomposición por números impares
    for (int i = 3; i <= num; i += 2) {
        while (num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
    }

    // Si num es mayor que 2, entonces es un número primo
    if (num > 2) {
        printf("%d ", num);
    }
    
    printf("\n");
}

int main(void) {
    int num;

    printf("Ingrese un numero para descomponerlo en factores primos: ");
    scanf("%d", &num);

    descomponer_factores_primos(num);

    return 0;
}
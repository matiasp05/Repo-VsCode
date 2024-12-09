/*
Desarrollar un programa que solicite al usuario el ingreso de un numero
entero y calcule el máximo común divisor de forma recursiva.
*/

#include <stdio.h>

// Función recursiva para calcular el MCD
int calcular_mcd(int a, int b) {
    if (b == 0) {
        return a; // Caso base: el MCD es el número no nulo
    }
    return calcular_mcd(b, a % b); // Llamada recursiva con el resto
}

int main() {
    int num1, num2;

    // Solicitar entrada al usuario
    printf("Ingrese el primer número entero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo número entero: ");
    scanf("%d", &num2);

    // Asegurarse de que los números sean positivos
    if (num1 < 0) num1 = -num1;
    if (num2 < 0) num2 = -num2;

    // Calcular el MCD
    int mcd = calcular_mcd(num1, num2);

    // Mostrar el resultado
    printf("El máximo común divisor de %d y %d es: %d\n", num1, num2, mcd);

    return 0;
}
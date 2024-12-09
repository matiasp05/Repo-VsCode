/*
Escribir una función que reciba un valor y calcule el factorial del mismo.
No debe imprimir el valor, debe solamente devolverlo.
Si no se puede calcular el factorial del valor recibido, la función deberá devolver 0, de lo contrario deberá devolver el valor calculado. 

Invocarla para los valores -8, 0, 1, 5; mostrando en cada caso lo que devuelve.

Definición: El factorial de un entero positivo n,  se define como el producto de todos los números enteros positivos desde 1 hasta n.  El factorial de 0 es 1.
*/

#include <stdio.h>

int factorial(int num){
    int i, resultado = 1;
    if(num<0){
        resultado = 0;
    } else if (num == 0){
        resultado = 1;
    } else {
        for(i=1; i<=num; i++){
            resultado *= i;
        }
    }
    return resultado;
}

int main (void){
    int num, resultado;

    printf("Ingrese un numero para sacar su factorial: ");
    scanf("%i", &num);

    resultado = factorial(num);

    if (resultado == 0){
        printf("No se puede sacar el factorial del numero %i.\n", num);
    } else {
        printf("El factorial de %i es: %i", num, resultado);
    }
    return 0;
}
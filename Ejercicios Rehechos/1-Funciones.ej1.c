/*
Escribir una función que reciba dos valores enteros y devuelva la suma de los valores entre el menor y el mayor de dichos números, incluídos.
No debe imprimir el valor, debe solamente devolverlo.

Invocarla para los valores (-2, 2); (5, -10); (0, -4); (10, 15) y (-3, -25); mostrando en cada caso lo que devuelve.
*/

#include <stdio.h>

int sumar_enteros(int num1, int num2){
    int i, resultado = 0;
    if(num1<num2){
        for(i=num1;i<=num2;i++){
            resultado += i;
        }
    } else {
        for(i=num2;i<=num1;i++){
            resultado += i;
        }        
    }
    return resultado;
}


int main(void){
    int num1, num2;
    printf("Sumade intervalos.\n");
    printf("Ingrese un numero: ");
    scanf("%i", &num1);

    printf("Ingrese un segundo numero: ");
    scanf("%i", &num2);

    int resultado = sumar_enteros(num1, num2);

    printf("El resultado del intervalo %i y %i es: %i", num1, num2, resultado);

    return 0;
}
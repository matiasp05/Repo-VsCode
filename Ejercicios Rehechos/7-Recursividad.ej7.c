/*
Desarrollar un programa que muestre la suma de los primeros N números
naturales. El numero N lo debe ingresar el usuario.
*/

#include <stdio.h>

int suma_num(int n){
    if(n==0){
        return 0;
    }
    return n + suma_num(n-1);
}

int main(void){
    int n;

    printf("Ingrese la cant. de numeros sucesivos naturales a sumar: ");
    scanf("%i", &n);

    if(n<0){
        printf("Los numeros negativos no son naturales.\n");
    }else{
        int suma = suma_num(n);
        printf("La suma de los primeros %i numeros naturales es: %i", n, suma);
    }
    return 0;
}
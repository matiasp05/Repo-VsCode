/*
 Desarrollar un programa que muestre los primeros N números naturales. El
numero N lo debe ingresar el usuario.
*/

#include <stdio.h>

void imprimir_recur(int n){
    if(n==0){
        return;
    }
    
    imprimir_recur(n-1);
    printf("%i", n);
}

int main(void){
    int n;

    printf("Ingrese la cant de numeros sucesivos naturales que desea imprimir: ");
    scanf("%i", &n);

    imprimir_recur(n);

    return 0;
}
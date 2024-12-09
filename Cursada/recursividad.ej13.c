/*
Desarrollar una función recursiva que compruebe si un número es binario.
Un número binario está formado únicamente por ceros y unos
*/

#include <stdio.h>

int es_binario(int numero){
    //caso base.
    if(numero == 0 || numero == 1){
        return 1;
    }

    int digito = numero % 10;

    if(digito != 0 && digito != 1){
        return 0; //no es binario.
    }

    return es_binario(numero/10);
}


int main(void){
    int numero;

    printf("Ingrese un numero binario: ");
    scanf("%i", &numero);

    if(es_binario(numero)){
        printf("El numero %i es binario.", numero);
    } else {
        printf("El numero %i no es binario.", numero);
    }

    return 0;
}
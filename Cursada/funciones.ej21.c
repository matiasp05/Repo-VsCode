/*
Escribir un subprograma que dados a y b devuelva el cociente y el resto de
la división entera, sin utilizar los operadores correspondientes al lenguaje.
Validar los tipos de datos de entrada.
*/

#include <stdio.h>
#include <stdbool.h>

bool validar_entrada(int a, int b, int *cociente, int *resto){
    bool entrada;
    entrada = false;
    if(b==0){
        entrada = false;
    } else {
        *cociente = 0;
        *resto = a;
        if((a<0 && b>0) || (a>0 && b<0)){
            while((*resto > 0 && b < 0) || (*resto < 0 && b > 0)){
                *resto += b;
                (*cociente)--;
            }
            if(*resto != 0){ //por si nos pasamos del resto 0 y queda negativo.
                *resto -= b;
                (*cociente)++;
            }
        } else { // si los signos son iguales.
            while((*resto >= b && a > 0) || (*resto <= b && a < 0)){
                *resto -= b;
                (*cociente)++;
            }
        }
        entrada = true;
    }
    return entrada;
}

int main(void){
    int a, b, cociente, resto;

    printf("Ingrese el valor a(dividendo): ");
    scanf("%i", &a);
    printf("Ingrese el valor b(divisor): ");
    scanf("%i", &b);

    bool resultado = validar_entrada(a, b, &cociente, &resto);

    if(resultado){
        printf("El cociente da como resultado: %i.\n", cociente);
        printf("El resto da como resultado: %i.\n", resto);
    } else {
        printf("La division no se puede realizar.\n");
    }
    return 0;
}
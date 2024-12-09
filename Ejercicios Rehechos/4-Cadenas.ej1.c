/*
Escribir un programa en C, que:
- declare una cadena para almacenar como máximo 40 caracteres y como valor inicial le asigne tu nombre y apellido
- recorra la cadena e imprima sólo las consonantes, una debajo de la otra
- indique cuantas consonantes hay en tu nombre y apellido
*/

#include <stdio.h>
#include <string.h>

#define MAX_TEXTO 40

int main(void){
    int i,contador = 0;

    char nombre[MAX_TEXTO] = "Matias Portela";
    char c = nombre[0];
    for(i=0;nombre[i] != '\0';i++){
        c = nombre[i];
        if((c>='A' && c<='Z') || (c>='a' && c<='z')){ //Verificar si es letra
            if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U'){
                printf("%c\n", c);
                contador++;
            }
        }
    }
    printf("Total de consonantes: %i\n", contador);

    return 0;
}
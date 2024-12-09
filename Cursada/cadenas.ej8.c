/*
Escribir una función en C, que reciba una cadena que representa una palabra o
una frase y devuelva si la misma es o no un palíndromo.
Un palíndromo, es una palabra o frase que se lee igual en ambos sentidos.
Probar la función con los siguientes casos de prueba:
- anilina (Es palíndromo)
- ojo (Es palíndromo)
- radar (Es palíndromo)
- reconocer (Es palíndromo)
- amar a roma (Es palíndromo)
- ana lava lana (Es palíndromo)
- a ti no, bonita (Es palíndromo)
- algoritmos y programas (No es palíndromo)
- lenguaje C (No es palíndromo)
Evitar realizar ciclos innecesarios.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

bool es_minuscula(char c){
    bool validar;
    if(c <= 'a' && c >= 'z'){
        validar = true;
    } else {
        validar = false;
    }
    return validar;
}

bool es_mayuscula(char c){
    bool validar;
    if(c <= 'A' && c >= 'Z'){
        validar = true;
    } else {
        validar = false;
    }
    return validar;
}

char pasar_minuscula(char c){ //Pasar a minuscula
    if(es_mayuscula(c)){
        c += 32;
    }    
    return c;
}

bool validar_palindromo(char *oracion){
    int inicio = 0;
    int final = strlen(oracion) - 1;
    bool validar;

    while(inicio<final && oracion[inicio] == oracion[final]){
        if(es_mayuscula(oracion[inicio])){
            pasar_minuscula(oracion[inicio]);
        }
        if(es_mayuscula(oracion[final])){
            pasar_minuscula(oracion[final]);
        }
        if(es_minuscula(oracion[inicio]) && es_minuscula(oracion[final])){
            validar = true;
            inicio++;
            final--;
        } else if(!es_minuscula(oracion[inicio]) && !es_mayuscula(oracion[inicio])){
            validar = false;
            inicio++;
        } else if(!es_minuscula(oracion[final]) && !es_mayuscula(oracion[final])){
            validar = false;
            final--;
        } else {
            validar = false;    
        }
    }
    return validar;
}

int main(void){
    char oracion[MAX];

    printf("Ingrese frase: ");
    fgets(oracion, MAX, stdin);

    if(validar_palindromo(oracion)){
        printf("Es palindromo.");
    } else {
        printf("No es palindromo.");
    }
    return 0;
}
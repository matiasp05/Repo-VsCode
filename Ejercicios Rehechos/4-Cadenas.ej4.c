/*
Escribir una función en C, que reciba como parámetro una cadena de tipo t_cadena, y devuelva 
la cantidad de palabras que hay en la cadena.
Considerar que una palabra está separada de otra, por uno ó más blancos.

No recorrer la cadena más de una vez.
Declare un tipo t_cadena acorde.
Escribir el programa que incluya a la función y las invocaciones con los siguientes ejemplos:

cant_palabras("El sol es amarillo.") devuevle 4
cant_palabras(" Hoy es   30 de Junio de   2021  ") devuevle 7
cant_palabras("30/06/2021") devuelve 1
cant_palabras("El  precio  es      $2.000.-    ") devuelve 4
cant_palabras("       ") devuelve 0
*/

#include <stdio.h>
#include <string.h>

#define MAX_TEXTO 100

typedef char Cadena[MAX_TEXTO];

int contador_palabras(Cadena texto){
    int i, contador=0;

    for(i=0;texto[i] != '\0';i++){
        if(texto[i] == ' '){
            contador++;
        }
    }
    
    return contador;
}

int main(void){
    Cadena texto;

    int i, n, contador = 0;

    printf("Ingrese la cantidad de cadenas a contar sus palabras: ");
    scanf("%i", &n);
    getchar();

    for(i=0;i<n;i++){
        printf("Ingrese la cadena: ");
        fgets(texto, MAX_TEXTO, stdin);

        //Eliminar salto de linea.
        size_t largo = strlen(texto);
        if(largo>0 && texto[largo-1] == '\n'){
            texto[largo-1] = '\0';
        }

        printf("\nCadena a contar: / %s /\n", texto);
        contador = contador_palabras(texto);
        printf("La cadena contiene %i palabras.", contador);
    }
    return 0;
}
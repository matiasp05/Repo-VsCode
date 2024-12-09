/*
Escribir una función en C, que reciba una cadena de no más de 50 caracteres.
La función debe devolver la cantidad de vocales minúsculas, no acentuadas, que hay en la cadena recibida.
Escribe un programa que haga uso de la función y que la pruebe al menos con 5 casos, por ejemplo:
contar_vocales("El sol es una estrella")
mostrar por cada invocación el valor que devuelve. 
Definir un tipo adecuado para la cadena a utilizar.
*/

#include <stdio.h>
#include <string.h>

#define MAX_TEXTO 50

typedef char Cadena[MAX_TEXTO];


int contar_vocales(Cadena texto){
    int i, contador = 0;
    for(i=0;texto[i] != '\0';i++){
        if(texto[i]=='a' || texto[i]=='e' ||texto[i]=='i' || texto[i]=='o'||texto[i]=='u' || texto[i]=='A'||texto[i]=='E' || texto[i]=='I' || texto[i]=='O' || texto[i]=='U'){
            contador++;
        }
    }
    return contador;
}

int main(void){
    Cadena texto;
    int n, contador = 0;
    printf("Ingrese cuantas cadenas desea ingresar: ");
    scanf("%i", &n);
    getchar();

    for(int i=0;i<n;i++){
        printf("Ingrese la cadena %i(Max. 50 caracteres):", i+1);
        fgets(texto, MAX_TEXTO,stdin);

        //Eliminar el salto de linea si esta presente.
        size_t largo = strlen(texto);
        if(largo>0 && texto[largo - 1] == '\n'){
            texto[largo-1] = '\0';
        }
        contador = contar_vocales(texto);
        printf("Cadena %i: %s\n", i+1, texto);
        printf("Cantidad de vocales presentes: %i\n", contador);
    }

    return 0;
}
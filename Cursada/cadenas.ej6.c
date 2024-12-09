/*
Escribir una función para validar una nueva clave de acceso.
La función deberá recibir una cadena de caracteres, que contendrá la clave
candidata, ingresada previamente por el usuario.
Devolverá true o false, dependiendo de si cumple o no con las siguientes
condiciones:
- La clave debe estar formada únicamente por, entre 4 y 8 caracteres numéricos
- Los caracteres no pueden ser todos iguales
Ejemplos:
validar("j2020") devuevle false
validar("2021a") devuevle false
validar("20X21") devuevle false
validar("2220") devuelve true
validar("23445776") devuelve true
validar("089") devuelve false
validar("027845321") devuelve false
validar("02784532") devuelve true
validar("33333") devuelve false
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 8

void caracteres_iguales(char *clave[], int largo, bool *iguales){
    int i;
    *iguales = false;
    char primer_caracter = clave[0];
    
    if(largo < 4 || largo > 8){
        *iguales = true;
    } else {
        for(i=1;clave[i] <= largo;i++){
            if(clave[i] != primer_caracter){
                *iguales = false;
            }
        }
    }
}

int main(void){
    char clave[9];
    int largo;
    bool iguales;
    printf("Ingrese su clave: ");
    fgets(clave, sizeof(clave), stdin);
    
    largo = strlen(clave) - 1;
    caracteres_iguales(clave, largo, &iguales);
    if(iguales == true){
        printf("No es posible poner esa clave.\nRecuerda que debe tener entre 4 y 8 caracteres, y no deben ser numeros iguales."); 
    } else {
        printf("La contraseña se ha guardado correctamente.");
    }
    return 0;
}

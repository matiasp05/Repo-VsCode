/*
Escribir un programa para cambiar un número binario de cuatro cifras a un número de base
a) Los datos a leer son 4 números de un dígito cada uno.
b) El dato es un solo número de 4 cifras.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//Verificamos si es un numero binario valido de 4 cifras.
bool validar_binario(char binario[]){
    bool validar = true;
    int i;
    int largo = strlen(binario);
    if(largo != 4){
        validar = false;
    }else{
        for(i=0;i<largo;i++){
            if(binario[i] != '0' && binario[i]!= '1'){
                validar = false;
            }
        }
    }
    return validar;
}

int binario_a_decimal(char binario[]){
    int decimal = 0;
    int i;
    for(i=0;i<largo)
}
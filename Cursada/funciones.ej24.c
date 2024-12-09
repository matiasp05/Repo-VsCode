/*
Escribir un subprograma que dada una fecha en formato aaaammdd la
convierta en los parámetros numéricos aaaa, mm y dd. 
*/

#include <stdio.h>

void dividir_fecha(int fecha, int *año, int *mes, int *dia){

    *año = fecha / 10000;
    *mes = (fecha % 10000) / 100;
    *dia = fecha % 100;
}

int main(void){
    int fecha, año, mes, dia;

    printf("Ingrese fecha (aaaammdd) sin guiones ni nada: ");
    scanf("%i", &fecha);

    dividir_fecha(fecha, &año, &mes, &dia);

    printf("Dia: %i.\nMes:%i.\nAño: %i.", dia, mes, año);
    return 0;
}
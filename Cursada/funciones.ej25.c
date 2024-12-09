/*
Escribir un subprograma que dado un tiempo expresado en segundos,
devuelva los parámetros numéricos horas, minutos y segundos. 
*/

#include <stdio.h>

#define MAX_HORAS 24
#define MAX_MINUTOS 60
#define MAX_SEGUNDOS 60

void calcular_tiempo(int segundos_usuario, int *horas, int *minutos, int *segundos){
    
    *horas = segundos_usuario / 3600;
    segundos_usuario %= 3600;
    *minutos = segundos_usuario / 60;
    *segundos = segundos_usuario %= 60;
}

int main(void){
    int segundos_usuario, horas, minutos, segundos;
    printf("Exprese la cantidad de segundos para convertirlo: ");
    scanf("%i", &segundos_usuario);

    horas = 0, minutos = 0, segundos = 0;
    calcular_tiempo(segundos_usuario, &horas, &minutos, &segundos);

    printf("Se han calculado %i:%i:%i.", horas, minutos, segundos);
    return 0;
}
/*
Cargar todos los padrones de aquellos alumnos que cursan la materia fundamentos de programación
durante el 2° cuadtrimestr del año 2024.

Luego se realizarán multiples busquedas sobre diferentes padrones para conocer si el alumno pertenece o no al curso.

Implementar un programa que permita la carga de los padrones y la busqueda eficiente de los mismos.
*/

#include <stdio.h>
#include <stdbool.h>

#define MF 100

typedef int Vector[MF];

void cargar_padrones(Vector vec, int cant_alumnos){
    int i;
    for(i=0;i<cant_alumnos;i++){
        printf("Ingrese el padron del Alumno %i:", i+1);
        scanf("%i", &vec[i]);
    }
}

bool busq_padron(Vector vec, int cant_Alumnos, int padron){
    int i;
    bool encontrado = false;
    for(i=0;i<cant_Alumnos;i++){
        if(vec[i] == padron){
            encontrado = true;
        }
    }
    return encontrado;
}

int main(void){
    Vector alumnos;

    int cant_alumnos, padron;

    printf("Ingrese cantidad de alumnos a listar: ");
    scanf("%i", &cant_alumnos);

    cargar_padrones(alumnos, cant_alumnos);

    padron = alumnos[0];
    while(padron != 0){
        printf("Ingrese el numero de padron a verificar(0 para finalizar): ");
        scanf("%i", &padron);

        if(busq_padron(alumnos, cant_alumnos, padron)){
            printf("El padron se encuentra en la lista.\n");
        } else {
            printf("El padron no se encuentra listado.\n");
        }
    }
    return 0;
}
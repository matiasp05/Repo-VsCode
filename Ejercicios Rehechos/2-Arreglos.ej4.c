/*
Ingresar las notas de los alumnos del curso de Algoritmos y programación 1 (finalizar la carga ingresando cero)
y luego mostrar el promedio de notas general, y todas las notas superiores al promedio calculado

notas:
- almacenar las notas en un vector, considerar un máximo fisico adecuado.
- hacer un adecuado uso del máximo lógico
*/

#include <stdio.h>
#define MF 5

typedef int Vector[MF];

void carga_notas(int v[], int *cant_alumnos){
    int i = 0, nota;

    while(i<MF && nota!=0){
        printf("Ingrese la nota del Alumno %i:", i+1);
        scanf("%i", &nota);

        if(nota!=0){
            v[i]=nota;
            i++;
        }
    }
    *cant_alumnos = i;
}

float promedio_notas(int v[], int cant_alumnos){
    int i;
    
    float suma_notas = 0;
    float promedio;

    for(i=0;i<cant_alumnos;i++){
        suma_notas+=v[i];
    }
    promedio = suma_notas/cant_alumnos;
    return promedio;
}

void notas_superiores(int v[], int cant_alumnos, float prom_gral){
    int i;
    for(i=0;i<cant_alumnos;i++){
        if(prom_gral<v[i]){
            printf("La nota del Alumno %i es superior al promedio. Nota: %i\n", i+1, v[i]);
        }
    }
}

int main(void){
    Vector notas;

    int cant_alumnos;

    float prom_gral;

    carga_notas(notas, &cant_alumnos);

    prom_gral = promedio_notas(notas, cant_alumnos);

    printf("El promedio general es: %2.f\n", prom_gral);

    notas_superiores(notas, cant_alumnos, prom_gral);

    return 0;
    
}
/*
Ingresar las notas de los alumnos del curso de Algoritmos y programación 1 (finalizar la carga ingresando cero)
y luego mostrar la cantidad de alumnos que aprobaron, considerando la nota de aprobación igual o mayor a cuatro.

notas:
- almacenar las notas en un vector, considerar un máximo fisico adecuado.
- hacer un adecuado uso del máximo lógico
*/

#include <stdio.h>

#define MF 5

typedef int Vector[MF];

void carga_notas(int v[], int *cant_alumnos){
    int i= 0, nota;

    printf("Ingrese las notas de los alumnos (finalizar con 0):\n");
    while(i<MF && nota!=0){
        printf("Ingrese nota del Alumno %i:", i+1);
        scanf("%i", &nota);

        if(nota!= 0){
            v[i] = nota;
            i++;
        }
    }

    (*cant_alumnos) = i;
}

void mostrar_aprobados(int v[], int cant_alumnos){
    int i;
    int num_aprobados=0;
    for(i=0;i<cant_alumnos;i++){
        if(v[i]>=4){
            num_aprobados++;
        }
    }
    printf("Aprobaron %i alumnos en el curso.\n", num_aprobados);

}

int main(void){
    Vector notas;
    
    int cant_alumnos = 0;

    carga_notas(notas, &cant_alumnos);

    mostrar_aprobados(notas, cant_alumnos);

    return 0;
}
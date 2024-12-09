/*
Ingresar los padrones y las notas de los alumnos
del curso de Algoritmos y programación 1(son 10 alumnos) , luego
mostrar los padrones de los alumnos que aprobaron.
*/

#include <stdio.h>
#define MF 10

typedef struct{
    int padron;
    int notas;
}Alumno;

void carga_notas(Alumno alum[]){
    int i;
    for(i=0;i<MF;i++){
        printf("Alumno %i.\n", i+1);

        printf("Ingrese el padron:");
        scanf("%i", &alum[i].padron);

        printf("Ingrese su nota:");
        scanf("%i", &alum[i].notas);
    }
}

int main(void){
    Alumno alumnos[MF];

    carga_notas(alumnos);

    printf("Los padrones de los alumnos aprobados.\n");
    for(int i=0;i<MF;i++){
        if(alumnos[i].notas >= 4){
            printf("Padron alumno %i: %i\n", i+1, alumnos[i].padron);
        }
    }

    return 0;
}

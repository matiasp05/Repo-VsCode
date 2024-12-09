/*
Se tiene una lista de alumnos de algoritmos y programación 1 con los siguientes datos:
 - Nombre [string]
 - Apellido [string]
 - Padrón [entero]
 - Curso [string]
 - Nota parcial [entero].

a) Realizar una función que permita la carga de alumnos.

b) Generar a partir de la tabla original, otra nueva tabla con una nueva estructura que contenga aquellos alumnos aprobados, con los siguientes datos.
 - Nombre y Apellido [string] con formato "apellido, nombre"
 - Curso [string]
 - Nota parcial [entero]

c) Mostrar los alumnos con mayor nota del curso "Curso 1"
Sugerencia:
  - definir todos los tipos de struct necesarios
  - utilizar funciones de string strcat, strcpy y srtcmp
*/

#include <stdio.h>
#include <string.h>

#define MAX_TEXTO 20
#define MAX_ALUMNOS 30

typedef struct{
    char nombre[MAX_TEXTO];
    char apellido[MAX_TEXTO];
    int padron;
    char curso[MAX_TEXTO];
    int nota_parcial;
}Alumno;

typedef struct{
    char nombre_apellido[50];
    char curso[MAX_TEXTO];
    int nota_parcial;
}Alumno_aprobado;

void carga_alumnos(Alumno alumnos[], int cant_alumnos){
    int i;

    for(i=0;i<cant_alumnos;i++){
        printf("\nAlumno %i:\n", i+1);

        printf("Ingrese nombre: ");
        fgets(alumnos[i].nombre, MAX_TEXTO, stdin);

        printf("Ingrese el apellido: ");
        fgets(alumnos[i].apellido, MAX_TEXTO, stdin);

        printf("Ingrese numero de padron: ");
        scanf("%i", &alumnos[i].padron);
        getchar();

        printf("Ingrese el curso: ");
        fgets(alumnos[i].curso, MAX_TEXTO, stdin);

        printf("Ingrese su nota parcial: ");
        scanf("%i", &alumnos[i].nota_parcial);
        getchar();
    }
}

void pasar_aprobados(Alumno_aprobado alumnos_aprobados[], Alumno alumnos[], int cant_alumnos, int *cant_aprobados){
    int i, j=0;
    for(i=0;i<cant_alumnos;i++){
        if(alumnos[i].nota_parcial>=4){
            //Apellido, Nombre
            strcpy(alumnos_aprobados[j].nombre_apellido, alumnos[i].apellido);
            strcat(alumnos_aprobados[j].nombre_apellido, ", ");
            strcat(alumnos_aprobados[j].nombre_apellido, alumnos[i].nombre);

            //Curso
            strcpy(alumnos_aprobados[j].curso, alumnos[i].curso);

            //Nota
            strcpy(alumnos_aprobados[j].nota_parcial, alumnos[i].nota_parcial);
            j++;
        }
    }
    *cant_aprobados = j;
}

void mejor_alumno(Alumno_aprobado alumnos_aprobados[], int cant_aprobados, char curso){
    int i;
    int mejor_nota=0;

    char mejores_alumnos[50 * cant_aprobados];

    for(i=0;i<cant_aprobados;i++){
        if(strcmp(alumnos_aprobados[i].curso, curso) == 0){
            if(alumnos_aprobados[i].nota_parcial>mejor_nota){
                strcpy(mejores_alumnos, alumnos_aprobados[i].nombre_apellido); // Reemplazamos la lista de nombres.
                mejor_nota = alumnos_aprobados[i].nota_parcial;
            }else if(alumnos_aprobados[i].nota_parcial == mejor_nota){
                // Si es igual a la mejor nota, concatenamos al string de mejores.
                strcat(mejores_alumnos, ". ");
                strcat(mejores_alumnos, alumnos_aprobados[i].nombre_apellido);
            }
        }
    }

    if(mejor_nota<4){
        printf("No hay alumnos aprobados.\n");
    }else{
        printf("Mejor nota del %s es: %i\n", curso, mejor_nota);
        printf("Los alumnos son:\n %s.\n", mejores_alumnos);
    }
}

int main(void){
    
    int cant_alumnos, cant_aprobados;
    Alumno alumnos[MAX_ALUMNOS];

    Alumno_aprobado alumnos_aprobados[MAX_ALUMNOS];

    printf("Ingrese la cantidad de alumnos que desea cargar: ");
    scanf("%i", &cant_alumnos);
    getchar();

    carga_alumnos(alumnos, cant_alumnos);

    pasar_aprobados(alumnos_aprobados, alumnos, cant_alumnos, &cant_aprobados);

    mejor_alumno(alumnos_aprobados, cant_aprobados, "Curso 1");

    return 0;
}
/*
Implementar una función que retorna un puntero a un vector de n struct del
tipo t_alumno (ver anexo), el cual apunta a un bloque de memoria dinámica,
respetando la siguiente declaración. En caso de no poder reservar la memoria,
retornar NULL.
t_alumno* crear_alumnos(int n);
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
} t_alumno;

t_alumno* crear_alumnos(int n) { //solo pide esto
    t_alumno *alumnos = NULL;
    alumnos = malloc(n * sizeof(t_alumno));
    if (alumnos == NULL) {
        return NULL;
    }
    return alumnos;
}

void ingresar_datos(t_alumno *alumno) {
    printf("Ingrese el padron: ");
    scanf("%d", &alumno->padron);

    printf("Ingrese el nombre: ");
    scanf("%s", alumno->nombre);

    printf("Ingrese el apellido: ");
    scanf("%s", alumno->apellido);
}

void mostrar_datos(const t_alumno *alumno) {
    printf("Padron: %d\n", alumno->padron);
    printf("Nombre: %s\n", alumno->nombre);
    printf("Apellido: %s\n", alumno->apellido);
}

int main(void) {
    int n, i;
    
    printf("Ingrese el numero de alumnos: ");
    scanf("%d", &n);
    
    t_alumno* alumnos = crear_alumnos(n);

    if (alumnos == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nIngrese los datos del alumno %d:\n", i + 1);
        ingresar_datos(&alumnos[i]);
    }

    for (i = 0; i < n; i++) {
        printf("\nDatos del alumno %d:\n", i + 1);
        mostrar_datos(&alumnos[i]);
    }

    free(alumnos);

    return 0;
}
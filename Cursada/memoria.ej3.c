/*
Escribir un programa el cual reserve memoria dinámica para almacenar un
struct del tipo t_alumno (ver anexo). Luego solicitar al usuario que ingrese los
datos del alumno y almacenarlos en la memoria previamente reservada.
Mostrar luego todos los datos del alumno. Liberar la memoria reservada al
finalizar el programa.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
} t_alumno;

void ingresar_datos(t_alumno *alumno) {
    printf("Ingrese el padron: ");
    scanf("%d", &alumno->padron);

    printf("Ingrese el nombre: ");
    scanf("%s", alumno->nombre);

    printf("Ingrese el apellido: ");
    scanf("%s", alumno->apellido);
}

void mostrar_datos(const t_alumno *alumno) {
    printf("\nDatos del alumno:\n");
    printf("Padron: %d\n", alumno->padron);
    printf("Nombre: %s\n", alumno->nombre);
    printf("Apellido: %s\n", alumno->apellido);
}

int main(void) {
    t_alumno *alumno = NULL;
    alumno = malloc(sizeof(t_alumno));

    if (alumno == NULL) {
        printf("Error al reservar memoria.\n");
    } else {
        ingresar_datos(alumno);
        mostrar_datos(alumno);
        free(alumno);
    }

    return 0;
}

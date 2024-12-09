/*
Utilizar memoria dinámica para almacenar una cierta cantidad de n palabras
ingresadas por el usuario. Crear una estructura de datos dinámica de dos
dimensiones que permita almacenar esta información. Mostrar toda la
información de la estructura luego de haber sido cargada. Liberar toda la
memoria al finalizar el programa.
typedef char* t_palabra;
typedef t_palabra* t_vec;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* t_palabra;
typedef t_palabra* t_vec;





void ingresar_palabras(t_vec palabras, int n) {
    char buffer[100];
    for (int i = 0; i < n; i++) {
        printf("Ingrese la palabra %d: ", i + 1);
        scanf("%s", buffer);
        palabras[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        if (palabras[i] == NULL) {
            printf("Error al reservar memoria.\n");
        }else{
            strcpy(palabras[i], buffer);
        }        
    }
}

void mostrar_palabras(t_vec palabras, int n) {
    printf("\nPalabras ingresadas:\n");
    for (int i = 0; i < n; i++) {
        printf("Palabra %d: %s\n", i + 1, palabras[i]);
    }
}

void liberar_memoria(t_vec palabras, int n) {
    for (int i = 0; i < n; i++) {
        free(palabras[i]);
    }
    free(palabras);
}

int main(void) {
    int n;
    printf("Ingrese la cantidad de palabras: ");
    scanf("%d", &n);

    t_vec palabras = (t_vec)malloc(n * sizeof(t_palabra));
    if (palabras == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    ingresar_palabras(palabras, n);
    mostrar_palabras(palabras, n);
    liberar_memoria(palabras, n);

    return 0;
}

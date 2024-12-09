/*
Se tiene un archivo de números telefónicos cuyos registros son de la forma: 
Característica de localidad (4 dígitos) 
Característica central (4 dígitos) 
Número (4 dígitos) 

Dado un número que representa una característica de localidad, listar todos los números telefónicos con dicha localidad. 

Suponer los siguientes casos: 
  a) El archivo no cabe en memoria y está desordenado. 
  b) El archivo no cabe en memoria y está ordenado según localidades crecientes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char localidad[5]; // Característica de localidad (4 dígitos + '\0')
    char central[5];   // Característica central (4 dígitos + '\0')
    char numero[5];    // Número (4 dígitos + '\0')
} t_telefono;

void listar_telefonos_por_localidad_desordenado(FILE *archivo, char *localidad_buscada) {

    t_telefono telefono;

    while (fread(&telefono, sizeof(t_telefono), 1, archivo) == 1) {
        if (strncmp(telefono.localidad, localidad_buscada, 4) == 0) {
            printf("(%s) %s-%s\n", telefono.localidad, telefono.central, telefono.numero);
        }
    }

    fclose(archivo);
}

int main() {
    FILE *archivo;
    archivo = fopen("telefonos.dat", "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo");
    } else {
        char localidad_buscada[5];
        printf("Ingrese la característica de localidad (4 dígitos): ");
        scanf("%4s", localidad_buscada);

        listar_telefonos_por_localidad_desordenado(localidad_buscada);

    }
    
    return 0;
}

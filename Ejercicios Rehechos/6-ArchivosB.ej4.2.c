#include <stdio.h>
#include <string.h>

#define MAX_VIAJES 100

typedef struct {
    char patente[10];
    char destino[30];
    float costo;
    float peso;
} Viaje;

typedef struct {
    char patente[10];
    float peso_total;
    int cant_viajes;
} ResumenCamion;

void procesar_datos(Viaje viajes[], int *n) {
    FILE *Archivo = fopen("Archivo.dat", "rb");
    if (Archivo == NULL) {
        printf("No se pudo abrir el archivo.");
    } else {
        *n = 0;
        while (fread(&viajes[*n], sizeof(Viaje), 1, Archivo) == 1) {
            (*n)++;
        }
    }

    if (*n == 0) {
        printf("No hay registros válidos en el archivo.\n");
    } else {
        printf("Se encontraron %i registros.\n", *n);
    }

    fclose(Archivo);
}

void grabar_resumen(Viaje viajes[], int n) {
    FILE *resumen = fopen("Resumen.dat", "wb");
    if (resumen == NULL) {
        printf("No se pudo crear el archivo de resumen.\n");
        return;
    }

    char patente_actual[10] = "";
    float peso_total = 0;
    int viajes_camion_actual = 0;
    int viajes_cordoba = 0;
    int max_viajes = 0;
    char patente_mas_viajes[10] = "";

    for (int i = 0; i < n; i++) {
        // Contar viajes a Córdoba
        if (strcmp(viajes[i].destino, "Cordoba") == 0) {
            viajes_cordoba++;
        }

        if (strcmp(viajes[i].patente, patente_actual) != 0) {
            // Grabar datos del camión anterior
            if (viajes_camion_actual > 0) {
                ResumenCamion resumen_camion;
                strcpy(resumen_camion.patente, patente_actual);
                resumen_camion.peso_total = peso_total;
                resumen_camion.cant_viajes = viajes_camion_actual;
                fwrite(&resumen_camion, sizeof(ResumenCamion), 1, resumen);

                if (viajes_camion_actual > max_viajes) {
                    max_viajes = viajes_camion_actual;
                    strcpy(patente_mas_viajes, patente_actual);
                }
            }

            // Actualizar datos del nuevo camión
            strcpy(patente_actual, viajes[i].patente);
            peso_total = viajes[i].peso;
            viajes_camion_actual = 1;
        } else {
            // Acumular datos del mismo camión
            viajes_camion_actual++;
            peso_total += viajes[i].peso;
        }
    }

    // Grabar el último camión
    if (viajes_camion_actual > 0) {
        ResumenCamion resumen_camion;
        strcpy(resumen_camion.patente, patente_actual);
        resumen_camion.peso_total = peso_total;
        resumen_camion.cant_viajes = viajes_camion_actual;
        fwrite(&resumen_camion, sizeof(ResumenCamion), 1, resumen);

        if (viajes_camion_actual > max_viajes) {
            max_viajes = viajes_camion_actual;
            strcpy(patente_mas_viajes, patente_actual);
        }
    }

    fclose(resumen);

    printf("El camión con más viajes fue: %s\n", patente_mas_viajes);
    printf("A Córdoba se realizaron %i viajes\n", viajes_cordoba);
}

int main(void) {
    Viaje viajes[MAX_VIAJES];
    int n;

    procesar_datos(viajes, &n);

    if (n > 0) {
        grabar_resumen(viajes, n);
    }

    return 0;
}
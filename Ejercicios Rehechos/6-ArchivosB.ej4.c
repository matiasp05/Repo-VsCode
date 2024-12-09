/*
Una empresa que transporta carga tiene en un archivo los siguientes datos
de cada viaje:
.a. Nro de patente de del camión
.b. Destino
.c. Costo del viaje
.d. Peso de la carga en KG
El archivo está ordenado por nro. de patente. Se pide:
.a. Informar el nro. de patente del camión que realizó más viajes
.b. Informar cuántos viajes se realizaron al destino “Córdoba”
.c. Grabar en un archivo, para cada camión, número de patente y cantidad
de kg. Transportados en total.
*/

#include <stdio.h>
#include <string.h>

#define MAX_VIAJES 100

typedef struct{
    char patente[10];
    char destino[30];
    float costo;
    float peso;
} Viaje;

typedef struct{
    char patente[10];
    float peso;
    int cant_viajes;
} ResumenCamion;

void procesar_datos(Viaje viajes[], int *n){
    FILE *Archivo = fopen("Archivo.txt", "r");
    if(Archivo==NULL){
        printf("No se pudo abrir el archivo.");
    } else {
        *n=0;
        while(fscanf(Archivo, "%9s %29s %f %f\n", viajes[*n].patente, viajes[*n].destino, &viajes[*n].costo, &viajes[*n].peso) == 4){
            (*n)++;
        }
    }
    if((*n)==0){
        printf("No hay registros validos en el archivo.\n");
    }else{
        printf("Se encontraron %i registros.\n", *n);
    }

    fclose(Archivo);
}

void grabar_resumen(Viaje viajes[], int n){
    FILE *resumen = fopen("Resumen.txt", "w");
    int i, viajes_cordoba = 0, max_viajes = 0;
    char patente_mas_viajes[10] = "";
    if(resumen == NULL){
        printf("No se pudo crear el archivo de resumen.\n");
    } else {
        char patente_actual[10] = "";
        float peso_total = 0;
        int viajes_camion_actual = 0;

        for (i = 0; i < n; i++) {
            // Contar viajes a Córdoba
            if(strcmp(viajes[i]. destino, "Cordoba") == 0){
                viajes_cordoba++;
            }
            // Cambio de camión
            if(strcmp(viajes[i].patente, patente_actual) != 0){

                if(viajes_camion_actual > max_viajes){
                    max_viajes = viajes_camion_actual;
                    strcpy(patente_mas_viajes, patente_actual);
                }
                //Grabar datos del camion anterior
                if (viajes_camion_actual > 0) {
                    fprintf(resumen, "Patente: %s - Peso total: %.2f - Cantidad de Viajes: %i", patente_actual, peso_total, viajes_camion_actual);
                }
                //Actualizo patente
                strcpy(patente_actual, viajes[i].patente);
                peso_total = viajes[i].peso;
                viajes_camion_actual = 1;
            }else{
                viajes_camion_actual++;
                peso_total += viajes[i].peso;
            }
        }

        //grabar ultimo resumen.
        if (viajes_camion_actual > 0) {
            fprintf(resumen, "Patente: %s - Peso total: %.2f - Cantidad de Viajes: %i", patente_actual, peso_total, viajes_camion_actual);
            if (viajes_camion_actual > max_viajes) {
                max_viajes = viajes_camion_actual;
                strcpy(patente_mas_viajes, patente_actual);
            }
        }
    }    
    fclose(resumen);

    printf("El camion con mas viajes fue: %s\n", patente_mas_viajes);
    printf("A Cordoba se hicieron %i viajes\n", viajes_cordoba);
}

int main(void){
    Viaje viajes[MAX_VIAJES];
    
    int n;

    procesar_datos(viajes, &n);

    if(n>0){
        grabar_resumen(viajes, n);
    }
    return 0;
}
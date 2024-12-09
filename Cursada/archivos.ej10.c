/*
Una escuela tiene en el archivo ARCHIVO.DAT, los siguientes datos de sus
alumnos: NOMBRE, AÑO, DIVISION, PROMEDIO GENERAL.
El archivo está ordenado en forma creciente por año y división. Se pide:
. • Imprimir un listado por año y división con los nombres de los
alumnos y sus promedios
. • Informar, al final del proceso, el nombre del alumno de mejor
promedio de la escuela
. • Grabar en un archivo los siguientes datos de cada año y división:
AÑO, DIVISION, CANTIDAD DE ALUMNOS 
*/

#include <stdio.h>

#define MAX_ALUMNOS 100
#define MAX_NOMBRE 50

typedef struct{
    char nombre[MAX_NOMBRE];
    int anio;
    char division;
    float promedio;
} Alumno;

typedef struct{
    int anio;
    char division;
    int cantidad_alumnos;
} ResumenAnioDivision;

void procesar_datos(Alumno alumnos[], int *n){
    FILE *arArchivo = fopen("ARCHIVO.txt", "r");
    if(arArchivo==NULL){
        printf("No se pudo abrir el archivo.");
    } else {
        *n = 0;

        while(fscanf(arArchivo, "%49s %d %c %f", 
              alumnos[*n].nombre, 
              &alumnos[*n].anio, 
              &alumnos[*n].division, 
              &alumnos[*n].promedio) == 4){
                (*n)++;
              }
    }
    if (*n == 0) {
        printf("No se encontraron registros válidos en el archivo.\n");
    } else {
        printf("Se leyeron %d registros.\n", *n);
    }
    
    fclose(arArchivo);
}

void imprimir_listado(Alumno alumnos[], int n){
    int i;
    printf("Listado de alumnos por año y division:\n");
    int anio_actual = -1;
    char division_actual = '\0';

    for(i=0;i<n;i++){
        if(alumnos[i].anio != anio_actual || alumnos[i].division != division_actual){
            anio_actual = alumnos[i].anio;
            division_actual = alumnos[i].division;
            printf("\nAnio: %i Division: %c\n", anio_actual,division_actual);
        }
        printf("Nombre: %s - Promedio: %.2f\n", alumnos[i].nombre, alumnos[i].promedio);
    }
}

void encontrar_mejor_alumno(Alumno alumnos[], int n, Alumno *mejor_alumno){
    *mejor_alumno = alumnos[0];

    for(int i=0;i<n;i++){
        if(alumnos[i].promedio > mejor_alumno->promedio){
            *mejor_alumno = alumnos[i];
        }
    }
}

void grabar_resumen(Alumno alumnos[], int n){
    FILE *resumen = fopen("RESUMEN.DAT", "w");

    if(resumen == NULL){
        printf("No se pudo crear el archivo de resumen.\n");
    } else {
        int anio_actual=-1;
        char division_actual='\0';
        int contador = 0;

        for(int i = 0; i<n;i++){
            if(alumnos[i].anio != anio_actual || alumnos[i].division != division_actual){
                if(contador > 0){
                    // Grabar el resumen anterior
                    fprintf(resumen, "Año: %d División: %c - Cantidad de Alumnos: %d\n", 
                            anio_actual, division_actual, contador);
                }
                anio_actual = alumnos[i].anio;
                division_actual = alumnos[i].division;
                contador = 1;
            } else {
                contador++;
            }
        }
        // Grabar el último resumen
        fprintf(resumen, "Año: %d División: %c - Cantidad de Alumnos: %d\n", anio_actual, division_actual, contador);
    }
    fclose(resumen);
}

int main(void){
    Alumno alumnos[MAX_ALUMNOS];
    Alumno mejor_alumno;
    int n;

    procesar_datos(alumnos, &n);

    if(n==0){
        printf("No se encontraron alumnos en el archivo.\n");
    } else {
        imprimir_listado(alumnos, n);
        encontrar_mejor_alumno(alumnos, n, &mejor_alumno);

        printf("\nEl alumno con mejor promedio es: %s con un promedio de %.2f.\n", mejor_alumno.nombre, mejor_alumno.promedio);

        grabar_resumen(alumnos, n);
    }
    return 0;
}
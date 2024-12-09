/*
Se tiene un archivo con los siguientes datos de los empleados de una
empresa: Apellido y Nombre (35 caracteres), Fecha de Nacimiento (día,
mes y año) ,Fecha de Ingreso (día , mes y año) y Sueldo Básico
Se conoce la fecha de procesamiento.
Se pide: 
a) imprimir un listado con los apellidos y nombres de las personas que
cumplan años en el mes
b) calcular e informar una suma de regalo equivalente al uno por mil del
sueldo por cada año cumplido. 
*/

#include <stdio.h>
#include <string.h>

#define MAX_EMPLEADOS 100
#define MAX_CARAC 36

typedef struct{
    char apellido_nombre[MAX_CARAC];
    int dia_nac, mes_nac, anio_nac;
    int dia_ing, mes_ing, anio_ing;
    float sueldo;
} Empleado;

void procesar_datos(Empleado empleados[], int *n){
    FILE *archivo = fopen("Archivo.txt", "r");
    if(archivo == NULL){
        printf("No se pudo abrir el archivo.\n");
    }else{
        *n=0;
        while(fscanf(archivo, "%35s %i/%i/%i %i/%i/%i %f", empleados[*n].apellido_nombre, &empleados[*n].dia_nac, &empleados[*n].mes_nac, &empleados[*n].anio_nac, &empleados[*n].dia_ing, &empleados[*n].mes_ing, &empleados[*n].anio_ing, &empleados[*n].sueldo) != EOF){
            (*n)++;
        }
    }
    if((*n)==0){
        printf("No hay registros en el archivo.\n");
    } else {
        printf("Se encontraron %i registros.\n", *n);
    }

    fclose(archivo);
}

void imprimir_cumpleaños(Empleado empleados[], int n, int mes_act){
    int i;

    printf("Empleados que cumplen en el mes %i:\n", mes_act);
    for(i=0;i<n;i++){
        if(empleados[i].mes_nac == mes_act){
            printf("%s\n", empleados[i].apellido_nombre);
        }
    }
}

void calcular_regalo(Empleado empleados[], int n, int mes_actual, int anio_actual){
    int i;
    printf("Regalo de cumpleaños:\n");
    for(i=0;i<n;i++){
        int edad = anio_actual - empleados[i].anio_nac;
        if(mes_actual<empleados[i].mes_nac || (mes_actual==empleados[i].mes_nac && mes_actual<empleados[i].mes_nac)){
            edad--;
        }
        float regalo = (empleados[i].sueldo * edad) / 1000;
        printf("%s: %.2f.\n", empleados[i].apellido_nombre, regalo); 
    }
}

int main(void){
    Empleado empleados[MAX_EMPLEADOS];

    int n;
    int dia_act, mes_act, anio_act;

    //pedir fecha actual.
    printf("Ingrese la fecha actual(DD MM AAAA): ");
    scanf("%i %i %i", &dia_act, &mes_act, &anio_act);

    procesar_datos(empleados, &n);
    if(n>0){
        imprimir_cumpleaños(empleados, n, mes_act);

        calcular_regalo(empleados, n, mes_act, anio_act);
    }
    return 0;
}

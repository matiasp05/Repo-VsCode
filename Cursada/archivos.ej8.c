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

#define MAX 100

typedef struct{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct{
    char nombre[36];
    Fecha fecha_nacimiento;
    Fecha fecha_ingreso;
    float sueldo;
} Empleado;


void leer_empleados(Empleado empleados[], int *n){
    FILE *arArchivo = fopen("empleados.ej8.txt", "r");
    
    *n = 0;
    if(arArchivo == NULL){
        printf("No se pudo abrir el archivo.\n"); 
    } else {
        while(fscanf(arArchivo, "%35[^\n] %d/%d/%d %d/%d/%d %f\n", 
                      empleados[*n].nombre, 
                      &empleados[*n].fecha_nacimiento.dia, 
                      &empleados[*n].fecha_nacimiento.mes, 
                      &empleados[*n].fecha_nacimiento.anio, 
                      &empleados[*n].fecha_ingreso.dia, 
                      &empleados[*n].fecha_ingreso.mes, 
                      &empleados[*n].fecha_ingreso.anio, 
                      &empleados[*n].sueldo) != EOF){
            (*n)++;
        }
    }
    fclose(arArchivo);
}

void imprimir_cumpleanios(Empleado empleados[], int n, int mes_actual){
    int i;
    printf("Empleados que cumplen años en el mes %i.\n", mes_actual);

    for (i = 0; i < n; i++){
        if(empleados[i].fecha_nacimiento.mes == mes_actual){
            printf("%s\n", empleados[i].nombre);
        }
    } 
}

void calcular_regalo(Empleado empleados[], int n, Fecha fecha_actual){
    printf("Regalo de cumpleaños:\n");
    for(int i=0;i<n;i++){
        int edad = fecha_actual.anio - empleados[i].fecha_nacimiento.anio;
        if(fecha_actual.mes == empleados[i].fecha_nacimiento.mes && fecha_actual.dia < empleados[i].fecha_nacimiento.dia){
            edad--;
        }
        float regalo = (empleados[i].sueldo / 1000) * edad;
        printf("%s: %.2f\n", empleados[i].nombre, regalo);
    }
}

int main(void){
    Empleado empleados[MAX];
    Fecha fecha_actual;

    int n;
    //Pedir la fecha actual.
    printf("Ingrese la fecha actual(DD MM AAAA): ");
    scanf("%d %d %d", &fecha_actual.dia, &fecha_actual.mes, &fecha_actual.anio);
    leer_empleados(empleados, &n);



    imprimir_cumpleanios(empleados, n, fecha_actual.mes);

    calcular_regalo(empleados, n, fecha_actual);

    return 0;
}
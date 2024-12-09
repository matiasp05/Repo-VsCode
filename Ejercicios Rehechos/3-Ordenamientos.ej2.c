/*
Escribir un programa modular que solicite el ingreso de la cantidad de productos vendidos en la semana, de lunes a domingo, de 0 a 23hs.
El ingreso de datos es por día comenzando el lunes, y para cada día, por hora de 0 a 23.

Se pide:
1. Calcular el promedio de ventas por cada dia
2. Calcular el promedio de ventas por cada hora
3. Mostrar el dia y hora en que mas se vendió

   0________23 (hora)
0   |_|_|_|_|_|
     |_|_|_|_|_|
     |_|_|_|_|_|
     |_|_|_|_|_|
6   |_|_|_|_|_|
(dia)
*/

#include <stdio.h>

#define MAX_HORA 24
#define MAX_DIA 7

typedef int Ventas[MAX_DIA][MAX_HORA];

void carga_ventas(Ventas venta){
    int i,j;
    for(i=0;i<MAX_DIA;i++){
        printf("\nIngrese las ventas del dia %i:\n", i+1);
        for(j=0;j<MAX_HORA;j++){
            printf("Ingrese ventas hora %i: ", j);
            scanf("%i", &venta[i][j]);
        }
    }
}

void promedio_dia(Ventas venta){
    int i,j,suma;
    for(i=0;i<MAX_DIA;i++){
        suma=0;
        for(j=0;j<MAX_HORA;j++){
            suma+=venta[i][j];
        }
        printf("Promedio de ventas del día %d: %.2f\n", i + 1, (float)suma/MAX_HORA);
    }
}

void promedio_hora(Ventas venta){
    int i,j,suma;
    for(i=0;i<MAX_HORA;i++){
        suma=0;
        for(j=0;j<MAX_DIA;j++){
            suma+=venta[j][i];
        }
        printf("Promedio de ventas en la hora %d: %.2f\n", i, (float)suma / MAX_DIA);
    }

}

void max_ventas(Ventas venta, int *max_venta, int *dia_max, int *hora_max){
    int i,j;
    *max_venta = venta[0][0];
    *hora_max = 0;
    *dia_max=0;

    for(i=0;i<MAX_DIA;i++){
        for(j=0;j<MAX_HORA;j++){
            if(venta[i][j]>*max_venta){
                *max_venta = venta[i][j];
                *hora_max=j;
                *dia_max=i;
            }
        }
    }
}

int main (void){
    Ventas venta[MAX_DIA][MAX_HORA];

    int max_venta, hora_max, dia_max;

    carga_ventas(venta);

    printf("\nPromedio por Dia.\n");
    promedio_dia(venta);

    printf("\nPromedio por Hora\n");
    promedio_hora(venta);

    max_ventas(venta, &max_venta, &dia_max, &hora_max);

    printf("La mayor venta fue el dia %i, hora %i: %i productos",dia_max, hora_max, max_venta);

    return 0;
}

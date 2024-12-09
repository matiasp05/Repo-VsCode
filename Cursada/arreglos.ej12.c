/*
Se tiene un registro de la temperatura por hora (0 a 23) por día (1 a n) de
un mes, ordenada cronológicamente. Se pide: 
a) Ingresar el número de mes para conocer la cantidad de días registrados. 
b) Cargar el listado en una matrize informarla en forma bidimensional. 
c) Informar además la máxima y la mínimatemperatura por día, la máxima y la mínima temperatura del mes.
*/

#include <stdio.h>
#define MAX_HORA 24
#define MAX_DIAS 32

void cargar_temp_mes(float temperatura[][MAX_HORA], int dias){
    int i, j;
    for(i=0;i<dias;i++){
        printf("Ingrese las temperaturas para el dia %i:\n", i + 1);
        for(j=0;j<MAX_HORA;j++){
            printf("Hora %i: ", j);
            scanf("%f", &temperatura[i][j]);
        }
    }
}

void imprimir_temperaturas(float temperatura[][MAX_HORA], int dias){
    int i, j;
    for(i=0;i<dias;i++){
        printf("-- Dia %i --\n", i+1);
        for(j=0;j<MAX_HORA;j++){
            printf("%.2f\t", temperatura[i][j]);
        }
        printf("\n");
    }
}

void max_min_temp_dia(float temperatura[][MAX_HORA], int dias){
    int i,j;
    float max, min;

    for(i=0;i<dias;i++){
        max = temperatura[i][0];
        min = temperatura[i][0];
        for(j=0;j<MAX_HORA;j++){
            if(temperatura[i][j] < min){
                min = temperatura[i][j];
            }
            if(temperatura[i][j] > max){
                max = temperatura[i][j];
            }
        }
        printf("Max temperatura dia %i: %.2f\n", i+1, max);        
        printf("Min temperatura dia %i: %.2f\n", i+1, min);   
    }       
}

void max_min_temp_mes(float temperatura[][MAX_HORA], int dias){
    int i,j;
    float max = temperatura[0][0];
    float min = temperatura[0][0];

    for(i=0;i<dias;i++){
        for(j=0;j<MAX_HORA;j++){
            if(temperatura[i][j] < min){
                min = temperatura[i][j];
            }
            if(temperatura[i][j] > max){
                max = temperatura[i][j];
            }
        }
    }       
    printf("Max temperatura del mes: %.2f\n", max);        
    printf("Min temperatura del mes: %.2f\n", min);   
}

int main(void){
    int dias, mes;
    float temperatura[MAX_DIAS][MAX_HORA];

    printf("Ingresar el numero de mes (1-12): ");
    scanf("%i", &mes);
    
    //Segun el mes, asigno numero de dias.
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12 ){
        dias = 32;
    } else{
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
            dias = 31;
        } else {
            dias = 29;
        }
    }

    cargar_temp_mes(temperatura, dias);
    
    printf("-- Temperaturas registradas --\n");
    imprimir_temperaturas(temperatura,dias);

    max_min_temp_dia(temperatura, dias);

    max_min_temp_mes(temperatura, dias);
    
    return 0;
}
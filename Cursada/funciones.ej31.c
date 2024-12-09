/*
En una competencia de salto en largo, se presentaron 20 participantes. De
cada uno se ingresa: Numero de participante, fecha de nacimiento
(dd/mm/aaaa) y los alcances de sus 3 saltos expresados en metros. El
mejor de los 3 saltos se considera como la mejor marca obtenida. Se pide:
a) Para cada participante mostrar por pantalla el Numero de participante, la
edad y la marca obtenida
b) Informar el Numero de participante del atleta que obtuvo la mejor marca
*/

#include <stdio.h>
#define PARTICIPANTES 20
#define MAX_SALTOS 3

void calcular_edad(int anio_actual, int anio_nacimiento[], int edades[]){
    int i;
    for(i=0;i<PARTICIPANTES;i++){
        edades[i] = anio_actual - anio_nacimiento[i];
    }
}

void mejor_marca_participante(float saltos[][MAX_SALTOS], float mejores_saltos[]){
    int i, j;
    for(i=0;i<PARTICIPANTES;i++){ 
        for(j=0;j<3;j++){
            if(saltos[i][j] > mejores_saltos[i]){
                mejores_saltos[i] = saltos[i][j];
            }
        }
    }
}

void mejor_marca(float mejores_saltos[], float *mejor_salto, int *mejor_participante){
    int i;
    for(i=0;i<PARTICIPANTES;i++){
        if(mejores_saltos[i]>*mejor_salto){
            *mejor_salto = mejores_saltos[i];
            *mejor_participante = i;
        }
    }
}

void pedir_datos(int num_participante[], int dia_nacimiento[], int mes_nacimiento[], int anio_nacimiento[], float saltos[][MAX_SALTOS]){
    int i, j;
    for(i=0;i<PARTICIPANTES;i++){
        printf("Ingrese numero de participante %i: ", i+1);
        scanf("%i", &num_participante[i]);
        printf("Ingrese su fecha de nacimiento.\n");
        printf("Dia: ");
        scanf("%i", &dia_nacimiento[i]);
        printf("Mes: ");
        scanf("%i", &mes_nacimiento[i]);
        printf("Año: ");
        scanf("%i", &anio_nacimiento[i]);
        for(j=0;j<MAX_SALTOS;j++){
            printf("Ingrese la distancia del salto %i(en metros): ", j+1);
            scanf("%f", &saltos[i][j]);
        }
        printf("\n");
    }
}

void imprimir_datos(int num_participante[], int edades[], float mejores_saltos[]){
    int i;
    for(i=0;i<PARTICIPANTES;i++){
        printf("-- Datos participante %i. --\n", i+1);
        printf("Numero del participante: %i\n", num_participante[i]);
        printf("Edad: %i\n", edades[i]);
        printf("Mejor salto: %.2f\n", mejores_saltos[i]);
        printf("\n");
    }
    printf("\n");
}

int main(void){
    int num_participante[PARTICIPANTES], edades[PARTICIPANTES], dia_nacimiento[PARTICIPANTES], mes_nacimiento[PARTICIPANTES], anio_nacimiento[PARTICIPANTES];
    float saltos[PARTICIPANTES][MAX_SALTOS], mejores_saltos[PARTICIPANTES];
    int anio_actual = 2024, mejor_participante;
    float mejor_salto;

    pedir_datos(num_participante, dia_nacimiento, mes_nacimiento, anio_nacimiento, saltos);
    calcular_edad(anio_actual, anio_nacimiento, edades);
    mejor_marca_participante(saltos, mejores_saltos);
    mejor_marca(mejores_saltos, &mejor_salto, &mejor_participante);

    imprimir_datos(num_participante, edades, mejores_saltos);

    printf("El mejor salto de la competencia fue de %.2f metros y fue del participante con numero %i.", mejor_salto,  num_participante[mejor_participante]);
    return 0;
}
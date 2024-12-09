/*
Escribir un subprograma que dadas las coordenadas polares r y α devuelva
las correspondientes coordenadas rectangulares x = r cos α , y = r sen α. 
*/

#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

void calcular_coord_rect(double r, double alpha_grados, double *x, double *y){
    double alpha = alpha_grados * (PI / 180);
    *x = r * cos(alpha);
    *y = r * sin(alpha);
}

int main(void){
    double x, y, r, alpha_grados;

    printf("Ingrese el valor de r: ");
    scanf("%lf", &r);
    printf("Ingrese el valor de alpha (en grados): ");
    scanf("%lf", &alpha_grados);

    calcular_coord_rect(r, alpha_grados, &x, &y);
    printf("-- Coordenadas Rectangulo --\n");
    printf("x = %lf\n", x);
    printf("y = %lf\n", y);
}
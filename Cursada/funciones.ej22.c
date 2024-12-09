/*
Escribir un subprograma que dadas 2 coordenadas rectangulares (x,y)
devuelva las correspondientes coordenadas polares r = ( x2 + y2 )½
y α = arctg ( y / x ) . 
*/


#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

void calcular_coord_polares(double x, double y, double *r, double *alpha){
    *r = sqrt( x * x + y * y);
    *alpha = atan2(y, x);
}

int main(void){
    double x, y, r, alpha;

    printf("Ingrese coordenada x: ");
    scanf("%lf", &x);
    printf("Ingrese coordenada y: ");
    scanf("%lf", &y);

    calcular_coord_polares(x, y, &r, &alpha);

    alpha = alpha * (180 / PI);
    printf("El valor de r es: %.2f.\n", r);
    printf("El valor de alpha es (en grados): %.2f.\n", alpha);

    return 0;
}
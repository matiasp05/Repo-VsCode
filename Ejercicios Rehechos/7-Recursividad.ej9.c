/*
Desarrollar un programa que solicite al usuario el ingreso de un numero
entero y lo muestre el resultado de sumar sus dígitos.
*/

#include <stdio.h>

int suma_digitos(int num){
    if(num == 0){
        return 0;
    }

    int suma = num%10;
    return suma + suma_digitos(num/10); //Llamamos recursivamente sin el ultimo digito
}

int main(void){
    int num;

    printf("Ingrese el numero que desea sumar sus digitos(entero): ");
    scanf("%i", &num);

    if(num<0){
        num = -num;
        int suma = suma_digitos(num);
        printf("La suma de los digitos -%i es: %i", num, suma);
    }else{
        int suma = suma_digitos(num);
        printf("La suma de los digitos %i es: %i", num, suma);
    }

    return 0;
}
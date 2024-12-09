/*
 Desarrollar un programa que solicite al usuario el ingreso de un numero
entero y lo muestre invertido. No se puede utilizar vectores.
*/

#include <stdio.h>

void invertir_numero(int num){
    if(num==0){
        return;
    }
    
    printf("%i", num%10); //Imprimimos el ultimo digito.
    invertir_numero(num / 10); //Llamamos recursivamente sin el ultimo digito
}

int main(void){
    int num;

    printf("Ingrese que numero desea invertir(entero): ");
    scanf("%i", &num);

    if(num<0){
        num = -num;
        printf("-");
    }
    invertir_numero(num);
    return 0;
}
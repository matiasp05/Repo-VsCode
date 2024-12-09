#include <stdio.h>

int sacar_factorial(int num){
    int i, resultado = 1;

    if (num == 0) {
        resultado = 1;
    } else {
        for (i = num; i > 1; i--) {
        resultado = resultado * i;
        }
    }

    
    return resultado;
}

int main(void){
    FILE *arNumeros, *arFactoriales;
    int numero;

    // Abrir el archivo de entrada en modo lectura
    arNumeros = fopen("numeros.txt", "r");
    arFactoriales = fopen("factoriales.txt", "w");
    if(arNumeros == NULL){
        printf("No se pudo abrir el archivo de entrada.");
    } else {
        while (fscanf(arNumeros, "%i", &numero) != EOF){
            if(numero >= 0){
                int resultado = sacar_factorial(numero);
                fprintf(arFactoriales, "%i! = %i\n", numero, resultado);
            }else{
                fprintf(arFactoriales, "%d! = No se puede calcular el factorial de un número negativo\n", numero);
            }
        }
    }
    
    // Cerrar los archivos
    fclose(arNumeros);
    fclose(arFactoriales);

    return 0;

}
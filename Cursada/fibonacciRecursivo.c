#include <stdio.h>

// Función recursiva para calcular el n-ésimo número de Fibonacci
int fibonacci_recursivo(int n) {
    if (n<=1) {
        return n;
    }
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

int main() {
    int n;
    // Solicitar al usuario ingresar el número n
    printf("Ingrese el numero n para calcular el n-esimo numero de Fibonacci: ");
    scanf("%i", &n);
    for(int i=0; i<n; i++){
        printf("%i\t", fibonacci_recursivo(i));
    }
     
    return 0;
}
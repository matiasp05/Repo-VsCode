/*
Desarrollar una función recursiva que comprube si un numero pasado como
parámetro es capicúa.
*/


int potencia(int base, int exponente){
    if(exponente == 0){
        return 1;
    }
    if(exponente == 1){
        return base;
    }

    return base * potencia(base, exponente-1);
}

int main(void){
    int base, exponente;

    printf("Ingrese base: ");
    scanf("%i", &base);

    printf("Ingrese exponente: ");
    scanf("%i", &exponente);

    int resultado = potencia(base, exponente);

    printf("El resultado de la potencia de %i elevado a %i es: %i", base, exponente, resultado);

    return 0;
}
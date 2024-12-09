#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TEXTO 1000
#define COSTO_3_CARAC 10
#define COSTO_FRACCION 8

bool es_caracter_valido(char c){
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == ' ' || c == '.' || c == ',' || c == ';' || c == ':' || c == '(' || c == ')');
}

bool es_espacio(char c){
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int contar_palabras(char *texto){
    int contador = 0;
    bool en_palabra = false;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (es_espacio(texto[i])) {
            en_palabra = false;
        } else if (!en_palabra) {
            en_palabra = true;
            contador++;
        }
    }

    return contador;
}

int calcular_costo(char *texto){
    int costo_total = 0;
    int longitud_palabra = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        if ((texto[i] >= 'A' && texto[i] <= 'Z') || (texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] >= '0' && texto[i] <= '9')) {
            longitud_palabra++;
        } else if (es_espacio(texto[i]) || texto[i] == '.' || texto[i] == ',' || texto[i] == ';' || texto[i] == ':' || texto[i] == '(' || texto[i] == ')') {
            if (longitud_palabra > 0) {
                costo_total += (longitud_palabra / 3) * COSTO_3_CARAC;
                if (longitud_palabra % 3 > 0) {
                    costo_total += COSTO_FRACCION;
                }
                longitud_palabra = 0;
            }
        }
    }

    // Handle the last word in the text if there is no punctuation or space after it
    if (longitud_palabra > 0) {
        costo_total += (longitud_palabra / 3) * COSTO_3_CARAC;
        if (longitud_palabra % 3 > 0) {
            costo_total += COSTO_FRACCION;
        }
    }

    return costo_total;
}

int main(void){
    char texto[MAX_TEXTO];

    printf("Ingrese el texto del telegrama (max %d caracteres): ", MAX_TEXTO);
    fgets(texto, MAX_TEXTO, stdin);

    // Remove the newline character if present
    size_t largo = strlen(texto);
    if (largo > 0 && texto[largo - 1] == '\n') {
        texto[largo - 1] = '\0';
    }

    // Validate that the text only contains allowed characters
    for (int i = 0; texto[i] != '\0'; i++) {
        if (!es_caracter_valido(texto[i])) {
            printf("El texto contiene caracteres no permitidos.\n");
            return 1;
        }
    }

    int num_palabras = contar_palabras(texto);
    int costo = calcular_costo(texto);

    printf("La cantidad de palabras es: %d\n", num_palabras);
    printf("El costo del telegrama es: $%d\n", costo);

    return 0;
}
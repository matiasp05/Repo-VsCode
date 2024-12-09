/*
 Leer un archivo de caracteres que representa un texto formado por
oraciones terminadas en punto. Copiarlo en otro archivo eliminando los
espacios superfluos. 
*/

#include <stdio.h>


void limpiar_espacios(FILE *arArcivo1, FILE *arArchivo2){
    char caracter;
    int es_espacio = 0;

    while((caracter = fgetc(arArcivo1)) != EOF){
        if(caracter != ' '){
            //Si no es un espacio, lo escribimos en el archivo final.
            fputc(caracter, arArchivo2);
            es_espacio = 0; //reseteamos variable para anunciar que no hya espacio previo.
        } else if(!es_espacio){
            //Si es un espacio pero no hay espacios previos, lo escribimos.
            fputc(caracter, arArchivo2);
            es_espacio = 1; //Indicamos que acabamos de escribir un espacio.
        }
    }
}

int main(void){

    FILE *arArchivo1;
    arArchivo1 = fopen("archivo.ej7.txt", "r");
    FILE *arArchivo2;
    arArchivo2 = fopen("archivo.final.ej7.txt", "w");    

    if (arArchivo1 == NULL) {
        printf("No se pudo abrir el archivo de entrada.\n");
    } else if (arArchivo2 == NULL) {
        printf("No se pudo abrir el archivo de salida.\n");
        fclose(arArchivo1);
    } else {
        limpiar_espacios(arArchivo1, arArchivo2);

        fclose(arArchivo1);
        fclose(arArchivo2);
    }
    return 0;
}
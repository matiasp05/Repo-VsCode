/*
Escribir una función en C que, reciba como primer parámetro, una cadena de tipo t_cadena, y 
devuelva como segundo parámetro, la misma cadena pero invertida, sin considerar los blancos. 
Sólo se deben invertir las posiciones con caracteres ciertos, y no aquellas posiciones 
potenciales a ser utilizadas pero que podrían contener caracteres inciertos.
Recorrer la cadena a lo sumo una vez.
Declare un tipo t_cadena acorde.
Escribir el programa que incluya a la función y las invocaciones con los siguientes casos y 
las impresiones para comprobar que devuelven lo correcto. 

Casos:

invertir_cadena("Hola, me llamo Ana.", cad_invertida) ==> cad_invertida: ".anAomallem,aloH"
invertir_cadena("234561", cad_invertida) ==> cad_invertida: "165432"
invertir_cadena("    ", cad_invertida) ==> cad_invertida:  ""
invertir_cadena("Somos o No somos", cad_invertida) ==> cad_invertida:  "somosoNsomoS"
*/

#include <stdio.h>
#include <string.h>

#define MAX_TEXTO 100

typedef char Cadena[MAX_TEXTO];

void invertir_cadena(Cadena original, Cadena invertida){
    int i, j=0;

    for(i=0;original[i] != '\0';i++){//Verificamos que no tenga espacio.
        if(original[i] != ' '){
            invertida[j++] = original[i];
        }
    }
    invertida[j]='\0';//Cerramos la cadena.

    //Invertimos la cadena.
    char temp;
    j-=1;
    for(i=0;i<j;i++){
        temp = invertida[i];
        invertida[i]=invertida[j];
        invertida[j]=temp;
        j--;
    }
}

int main(void){
    Cadena original, invertida;
    int n, i;
    printf("Ingrese cuantas cadenas desea invertir: ");
    scanf("%i", &n);
    getchar();

    for(i=0;i<n;i++){
        printf("Ingrese la cadena a invertir: ");
        fgets(original, MAX_TEXTO, stdin);
        
        //Eliminar salto de linea sie sta presente.
        size_t largo = strlen(original);
        if(largo>0 && original[largo - 1] == '\n'){
            original[largo-1] = '\0';
        }

        printf("\nCadena original: /%s/\n", original);
        invertir_cadena(original, invertida);
        printf("\nCadena invertida: /%s/\n", invertida);
    }

    return 0;
}
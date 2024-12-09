/*
Escribir una función que recibirá por parámetro, una palabra, que representa un
sustantivo en singular.
La función deberá devolver, el plural de dicho sustantivo, aplicando las
siguientes reglas:
a. Agregar una “s” al final, si la palabra termina en vocal sin acento.
b. Agregar una “s” al final, si la palabra termina con una é (acentuada).
c. Si la palabra termina en “z”, la reemplazamos por “ces”.
d. Agregamos “es” al final, si la palabra termina en una consonante (a excepción
de la “s”, la “z”, y la “x”), ó si la palabra termina con las vocales acentuadas: á,
í, ó, ú.
e. Si el sustantivo termina en “s” ó “x”, entonces el plural es igual al singular,
por lo tanto la función deberá devolver lo mismo que recibió.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

bool vocal_sin_acento(char c){
    bool sin_acento = false;
    if(c == 'a' || c == 'e'|| c == 'i'|| c == 'o'|| c == 'u'){
        sin_acento = true;
    }
    return sin_acento;
}

void convertir_plural(char *sustantivo){
    int largo = strlen(sustantivo);

    //regla a y b.
    if(vocal_sin_acento(sustantivo[largo-1]) || sustantivo[largo-1] == 'é'){
        strcat(sustantivo, "s");
    //regla c.
    }else if(sustantivo[largo-1] == 'z'){
        sustantivo[largo-1] = 'c';
        strcat(sustantivo, "es");
    //regla d y e.
    } else if(sustantivo[largo-1] != 's' && sustantivo[largo-1] != 'x'){
        strcat(sustantivo, "es");
    }
    
}

int main(void){
    char sustantivo[MAX];

    printf("Ingrese un sustantivo para cambiarlo a plural: ");
    fgets(sustantivo, sizeof(sustantivo), stdin);
    fflush(stdin);

    //Eliminar salto de linea.
    int largo = strlen(sustantivo);
    if(sustantivo[largo-1] == '\n'){
        sustantivo[largo-1] = '\0';
    }

    convertir_plural(sustantivo);

    printf("El sustantivo luego de pasarlo a plural, queda: %s", sustantivo);
    
    return 0;
}
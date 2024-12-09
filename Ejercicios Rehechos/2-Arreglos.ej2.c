/*
Tomando como base el código que está debajo, modificalo para que:
-  los valores del arreglo sean cada uno de los dígitos de tu padrón/legajo 
-  declará un tipo de dato para el arreglo y una constante para su máximo físico.
-  mostrá del último elemento al primer elemento.

#include <stdio.h>

void mostrar_datos(int v[], int ultima_pos){
    int i;
    for(i=0;i<=ultima_pos;i++){
        printf("%i \n", v[i]);
    }
}

void main(){
    int v_nros[] = {2,4,6,8,10};

    mostrar_datos(v_nros, 4);
    return;
}
*/

#include <stdio.h>
#define MF 10

typedef int Vector[MF];

void mostrar_datos(int v[], int ML){
    int i;

    int ultima_pos = ML - 1;
    
    for(i=ultima_pos;i>=0;i--){
        printf("%i \t", v[i]);
    }
}

int main(void){
    Vector v_nros = {1,1,1,4,6,8};

    mostrar_datos(v_nros, 6);
    return 0;
}
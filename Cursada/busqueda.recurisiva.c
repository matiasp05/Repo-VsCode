#include <stdio.h>
#define MAX 10

typedef int Tvec[MAX];

int busqueda_binaria(Tvec vector, int inf, int sup, int buscado){
    if(buscado>vector[sup] || buscado<vector[inf]){
        return -1;
    } else {
        int mit=(sup+inf)/2;
        if (buscado==vector[mit]){
            return mit;
        }
        else 
        if (buscado>vector[mit]){
            return busqueda_binaria(vector,mit+1,sup,buscado);
        } else{
            return busqueda_binaria(vector, inf, mit-1, buscado);
        }
    }
}

int main(void){
    Tvec vect={1,2,4,5,6};
    int posicion;

    posicion = busqueda_binaria(vect, 0, 4, 2);

    if (posicion != -1){
       printf("La posicion del numero buscado es %i", posicion + 1);
    } else {
        printf("La posicion no se encontro");
    }

    return 0;
}
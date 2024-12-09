/*
 Desarrollar una función recursiva para realizar una búsqueda binaria en un
vector.
*/

#include <stdio.h>
#define MAX 10
typedef int Tvec[MAX];

int busq_binaria(Tvec Vector, int inicio, int final, int buscado){
    if(buscado>Vector[final] || buscado<Vector[inicio]){
        return -1;
    }else{
        int mitad= (inicio+final)/2;
        if(buscado==Vector[mitad]){
            return mitad;
        }else if(buscado>Vector[mitad]){
            return busq_binaria(Vector, mitad+1, final, buscado);
        }else{
            return busq_binaria(Vector, inicio, mitad-1, buscado);
        }
    }
}

int main(void){
    Tvec Vector = {1, 3, 6, 8, 10};
    int posicion;
    int buscado;
    printf("Que numero desea buscar? ");
    scanf("%i", &buscado);

    posicion = busq_binaria(Vector, 0, 4, buscado);
    if(posicion != -1){
        printf("La posicion buscada es: %i", posicion);
    } else{
        printf("No se encontro la posicion");
    }
    return 0;
}
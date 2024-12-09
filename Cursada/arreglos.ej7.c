/*
Dado un vector a de longitud n y un elemento p del mismo tipo que los
elementos del vector, buscar p en el vector a y devolver la posición que ocupa
en caso de encontrarlo o una señal en caso contrario. Suponer que no hay
repeticiones.
*/

#include <stdio.h>
#define MAX 100

typedef int Tvector[MAX];

void cargar_vector(Tvector v, int n){
    int i;

    for(i=0;i<n;i++){
        printf("Ingrese el numero posicion [%i]: ", i+1);
        scanf("%i", &v[i]);
    }
}

void mostrar_vector(Tvector v, int n){
    int i;
    
    printf("-- Vector --\n");
    for(i=0;i<n;i++){
        printf("%i\t", v[i]);   
    }
}

int busqueda_elemento(Tvector v, int n, int p){
    int i = 0;
    int encontrado = -1;
    while(encontrado == -1 && i<n){
        if(v[i] == p){
            encontrado = i;
        }
        i++;
    }
    return encontrado;
}

int main(void){
    Tvector vector;
    int p, n;

    printf("Ingrese el numero de elementos: ");
    scanf("%i", &n);

    cargar_vector(vector, n);

    printf("Ingrese el elemento a buscar: ");
    scanf("%i", &p);

    mostrar_vector(vector, n);

    int posicion = busqueda_elemento(vector, n, p);
    if(posicion == -1){
        printf("\nNo se pudo encontrar el elemento %i en el vector.\n", p);
    } else {
        printf("\nEl elemento %i se encuentra en la posicion %i del vector.\n", p, posicion + 1);
    }
    return 0;
}
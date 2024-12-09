/*
Dado un vector a de longitud n ordenado ascendente y un elemento p del
mismo tipo que los elementos del vector, intercalar p en el vector a de modo
que siga ordenado.
*/

#include <stdio.h>

#define MF 100

void leer_vector(int *n, int v[]){
    int i;
    printf("Ingrese el tamaño del vector: ");
    scanf("%i", n);

    for(i=0;i<*n;i++){
        printf("Ingrese el elemento %i del vector: ", i+1);
        scanf("%i", &v[i]);
    }
}

void imprimir_vector(int n, int v[]){
    int i;
    for(i=0;i<n;i++){
        printf("%i\t", v[i]);
    }
    printf("\n");
}

void ordenar_vector(int n, int v[]){ //Ordeno el vector por las dudas.
    int i,j,aux;
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            if(v[j]>v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}

void insertar_elemento(int *n, int v[], int p){
    int i;
    i= *n - 1;

    if (*n < MF) {
        while(i>=0 && v[i]>p){
            v[i+1] = v [i];
            i--;
        }

        v[i+1] = p;
        (*n)++;        
    } else {
        printf("Error: no hay espacio suficiente en el vector.\n");
    }    
}

int main(void){
    int n, p;
    int v[MF];
    

    leer_vector(&n, v);
    printf("VECTOR ORIGINAL.\n");
    
    imprimir_vector(n, v);

    ordenar_vector(n, v);

    printf("VECTOR ORDENADO.\n");
    imprimir_vector(n,v);

    printf("Ingrese elemento a insertar en el vector: ");
    scanf("%i", &p);
    
    insertar_elemento(&n, v, p);
    imprimir_vector(n,v);

    return 0;
}
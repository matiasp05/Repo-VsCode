
#include <stdio.h>

void ordenar(Tvector vector, int n){
    int i, j, aux;
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            if(vector[j]>vector[j+1]){
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
}
/*
Escribir un programa modular en C, que solicite el ingreso de 3 oraciones, de 
no más de 50 caracteres cada una. 
Luego informar: 
1. Cuál es la oración más larga. 
2. Si hay al menos 2 oraciones iguales. 
3. Solicitar el ingreso de una palabra o parte de una oración, e indicar si la 
misma se encuentra en las oraciones, y en cuales.
*/ 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_ORACIONES 3
#define MAX_CARACTERES 50

void ingresar_oraciones(char oraciones[MAX_ORACIONES][MAX_CARACTERES]){
  int i;
  for(i=0;i<MAX_ORACIONES;i++){
    printf("Ingrese la oracion %i: ", i+1);
    fgets(oraciones[i],MAX_CARACTERES,stdin);

    size_t largo = strlen(oraciones[i]);
    if(largo>0 && oraciones[i][largo - 1] == '\n'){
        oraciones[i][largo-1] = '\0';
    }
  }
}
void mostrar_oraciones(char oraciones[MAX_ORACIONES][MAX_CARACTERES]){
  int i;
  for(i=0;i<MAX_ORACIONES;i++){
    printf("La oracion %i es: %s\n", i+1, oraciones[i]);
  }
}

void oracion_mas_larga(char oraciones[MAX_ORACIONES][MAX_CARACTERES], int *max_longitud, int *posicion_max){
  int i, longitud;
  *max_longitud = 0;
  *posicion_max = 0;
  for(i=0;i<MAX_ORACIONES;i++){
    longitud = strlen(oraciones[i]);
    if(longitud > *max_longitud){
      *max_longitud = longitud;
      *posicion_max = i;
    }
  }
}

bool palabras_iguales(char oraciones[MAX_ORACIONES][MAX_CARACTERES]){
  int i,j;
  bool iguales = false;
  for(i=0;i<MAX_ORACIONES;i++){
    for(j=i+1;j<MAX_ORACIONES;j++)
      if(strcmp(oraciones[i],oraciones[j])==0){
        iguales = true;
      }
  }
  return iguales;
}

void buscar_oraciones(char oraciones[MAX_ORACIONES][MAX_CARACTERES], char palabra[MAX_CARACTERES], bool posiciones[MAX_ORACIONES]) {
  for (int i = 0; i < MAX_ORACIONES; i++) {
    if (strstr(oraciones[i], palabra) != NULL) {
      posiciones[i] = true;
    } else {
      posiciones[i] = false;
    }
  }
}


int main(void){
  char oraciones[MAX_ORACIONES][MAX_CARACTERES];
  int max_longitud = 0;
  int posicion_max = 0;
  bool posiciones[MAX_ORACIONES];
  char palabra[MAX_CARACTERES];
  
  ingresar_oraciones(oraciones);
  mostrar_oraciones(oraciones);
  oracion_mas_larga(oraciones, &max_longitud, &posicion_max);
  printf("La oracion mas larga tiene %i caracteres. Es:\n%s\n", max_longitud, oraciones[posicion_max]);

  if(palabras_iguales(oraciones)){
    printf("Hay al menos 2 oraciones iguales\n");
  }else{
    printf("No hay oraciones iguales\n");
  }
  
  printf("Ingrese una palabra o parte de una oracion:");
  fgets(palabra,MAX_CARACTERES,stdin);
  size_t largo = strlen(palabra);
  if(largo>0 && palabra[largo - 1] == '\n'){
    palabra[largo-1] = '\0';
  }

  buscar_oraciones(oraciones, palabra, posiciones);
  bool found = false;
  for (int i = 0; i < MAX_ORACIONES; i++) {
      if (posiciones[i]) {
          printf("La palabra \"%s\" se encuentra en la oracion %d: %s\n", palabra, i + 1, oraciones[i]);
          found = true;
      }
  }
  if (!found) {
      printf("La palabra \"%s\" no se encuentra en ninguna oracion\n", palabra);
  }
  return 0;
}
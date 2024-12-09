/*

Dada la siguiente estructura:



typedef struct{

  int padron;

  char ape_nom[30];

  float nota;

}t_regAlumno;



Escriba un programa modular que permita dar de alta registros de tipo t_regAlumno.

El usuario debe poder continuar ingresando datos hasta que ingrese un padron igual a 0.

Asuma que el archivo es inexistente.

Deberá subir el archivo generado, con al menos 5 datos de alumnos.

tipo binario.

*/



#include <stdio.h>



typedef struct{

  int padron;

  char ape_nom[30];

  float nota;

}t_regAlumno;



void alta_alumno(FILE *arAlumnos){

  t_regAlumno reg;

  printf("Ingrese el padron (0 para continuar): ");
  scanf("%i", &reg.padron);
  fflush(stdin);

  while(reg.padron != 0){

    printf("Ingrese apellido y nombre: ");
    scanf("%s", &reg.ape_nom);
    fflush(stdin);

    printf("Ingrese nota del alumno: ");
    scanf("%f", &reg.nota);
    fflush(stdin);

    fwrite(&reg, sizeof(reg), 1, arAlumnos);

    printf("Ingrese el padron (0 para continuar): ");
    scanf("%i", &reg.padron);

  }

  

}



int main(void){

  FILE *arAlumnos;
  arAlumnos = fopen("alumnos.dat", "wb");

  if(arAlumnos == NULL){
    printf("No se pudo abrir el archivo");
  } else {
    alta_alumno(arAlumnos);
    fclose(arAlumnos);
  }

  return 0;

}
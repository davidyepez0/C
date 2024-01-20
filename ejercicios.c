#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#define PI 3.1416

//while ((getchar()) != '\n');              Para limpiar el bufer de entrada y que permita escribir
//string[strcspn(string, "\n")] = '\0';      Para intercambiar el salto de linea por nulo
// void estaOrdenado(int vec[10]){
//   int x;
//   int ordenado=1;
//   for(x=0;x<9;x++){
//     if (vec[x+1]<vec[x]){
//       ordenado=0;
//     }
//   }
//   if (ordenado==1){
//     printf("Los elementos del vector estan ordenados");
//   }
//   else{
//     printf("Los elementos del vector no estan ordenados");
//   }
// }
// & para obtener la direccion de memoria de una variable
// * para acceder a lo apuntado
// (*pe)++ para que se modifique a lo que esta apuntando pe

struct nodo{
  int info;
  struct nodo *sig;
};

struct nodo *raiz = NULL;
struct nodo *fondo = NULL;

int vacia(){
  if(raiz == NULL)
    return 1;
  else
    return 0;
}

void insertar(int x){
  struct nodo *nuevo;
  nuevo = malloc(sizeof(struct nodo));
  nuevo->info = x;
  nuevo->sig = NULL;
  if(vacia()){
    raiz = nuevo;
    fondo = nuevo;
  }
  else{
    fondo->sig = nuevo;
    fondo = nuevo;
  }
}

int extraer(){
  if(!vacia()){
    int informacion = raiz->info;
    struct nodo *bor = raiz;
    if(raiz == fondo){
      raiz = NULL;
      fondo = NULL;
    }
    else{
      raiz = raiz->sig;
    }
    free(bor);
    return informacion;
  }
  else
    return -1;
}

void liberar(){
  struct nodo *reco = raiz;
  struct nodo *bor;
  while(reco != NULL){
    bor = reco;
    reco = reco->sig;
    free(bor);
  }
}

int cantidad(){
  struct nodo *reco = raiz;
  int cant = 0;
  while(reco != NULL){
    cant++;
    reco = reco->sig;
  }
  return cant;
}

void simulacion(){
  srand(time(NULL));
  int estado = 0;
  int llegada = rand() % 2 + 2;
  int salida = -1;
  int cantAtendidas = 0;
  int minuto;
  for(minuto = 0; minuto < 600; minuto++){
    if(llegada == minuto){
      if(estado == 0){
        estado = 1;
        salida = minuto + 2 + rand() % 3;
      }
      else{
        insertar(minuto);
      }
      llegada = minuto + 2 + rand() % 2;
    }
    if(salida == minuto){
      estado = 0;
      cantAtendidas++;
      if(!vacia()){
        extraer();
        estado = 1;
        salida = minuto + 2 + rand() % 3;
      }
    }
  }
  printf("Atendidos: %i\n", cantAtendidas);
  printf("En cola: %i\n", cantidad());
  printf("Minuto llegada: %i", extraer());
}

int main() {
  simulacion();
  liberar();
  getch();
  return 0;
}



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
  char a;
  struct nodo *sig;
};

struct nodo *raiz = NULL;

void cargar(char ecuacion){
  struct nodo *nuevo;
  nuevo = malloc(sizeof(struct nodo));
  nuevo->a = ecuacion;
  if(raiz == NULL){
    raiz = nuevo;
    nuevo->sig = NULL;
  }
  else{
    nuevo->sig = raiz;
    raiz = nuevo;
  }
}

char extraer(){
  if(raiz != NULL){
    int b = raiz->a;
    struct nodo *bor = raiz;
    raiz = raiz->sig;
    free(bor);
    return b;
  }
  else{
    return -1;
  }
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

int vacia(){
    if(raiz == NULL)
        return 1;
    else
        return 0;
}

void cargarFormula(char *formula){
  printf("Ingrese la formula: ");
  gets(formula);
}

int verificar(char *formula){
  for(int i = 0; i < strlen(formula); i++){
    if(formula[i] == '(' || formula[i] == '[' || formula[i] == '{'){
      cargar(formula[i]);
    }
    else if(formula[i] == ')'){
      if(extraer() != '('){
        return 0;
      }
    }
    else if(formula[i] == ']'){
      if(extraer() != '['){
        return 0;
      }
    }
    else if(formula[i] == '}'){
      if(extraer() != '{'){
        return 0;
      }
    }
  }
  if(vacia())
    return 1;
  else
    return 0;
}

int main() {
  char formula[100];
  cargarFormula(formula);
  if(verificar(formula)){
    printf("La formula esta correctamente balanceada");
  }
  else{
    printf("La formula no esta correctamente balanceada");
  }
  liberar();
  getch();
  return 0;
}



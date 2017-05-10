#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

struct Lista{
  int info;
  struct Lista *prox;
};

typedef struct Lista lista;

lista* listaConstrutor(){
  return NULL;
}

lista* listaPush(lista *l,int valor){
  lista *novo=(lista*)malloc(sizeof(lista));
  novo->info=valor;
  novo->prox=l;

  return novo;
}

lista* listaPop(lista *l,int valor){
  lista *contador=(lista*)malloc(sizeof(lista));
  lista *anterior=NULL;

  for(contador=l;contador!=NULL;contador=contador->prox){
    if(contador->info==valor){
      break;
    }
    anterior=contador;
  }

  if(contador==NULL){
    return l;
  }
  else if(anterior==NULL){
    l=l->prox;
  }
  else{
    anterior->prox=contador->prox;
  }
  return l;
}

lista* listaPushOrdenado(lista *l,int valor){
  lista *contador=(lista*)malloc(sizeof(lista));
  lista *anterior=NULL;

  lista *novo=(lista*)malloc(sizeof(lista));
  novo->info=valor;
  if(l==NULL){
    novo->prox=l;
    return novo;
  }

  for(contador=l;contador!=NULL;contador=contador->prox){
    if(valor<=contador->info){
        break;
    }
    anterior=contador;
  }

  if(anterior==NULL){
    novo->prox=l;
    l=novo;
  }
  else{
    novo->prox=anterior->prox;
    anterior->prox=novo;
  }
  return l;
}

void listaImprime(lista *l){
  lista *contador=(lista*)malloc(sizeof(lista));
  for(contador=l;contador!=NULL;contador=contador->prox){
    printf("%d\n",contador->info);
  }
}

int main(){
  lista *l;
  l=listaConstrutor();
  l=listaPushOrdenado(l,22);
  l=listaPushOrdenado(l,62);
  l=listaPushOrdenado(l,1);
  l=listaPushOrdenado(l,2);
  l=listaPushOrdenado(l,30);
  l=listaPushOrdenado(l,100);

  l=listaPop(l,1);
  listaImprime(l);
  return 0;
}

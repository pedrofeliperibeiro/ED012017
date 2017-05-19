#include <stdio.h>
#include <stdlib.h>

struct Lista{
  int info;
  struct Lista *prox;
};

typedef struct Lista lista;

lista* lista_construtor(){
  return NULL;
}

lista* lista_insere(lista *l,int valor){
  lista *novo= (lista*)malloc(sizeof(lista));
  novo->info=valor;
  novo->prox=l;
  return novo;
}

lista* lista_retira_fim(lista* l){
  lista *aux=(lista*)malloc(sizeof(lista));
  aux=l;
  l=l->prox;
  free(aux);
  return l;
}

lista* lista_retira_inicio(lista* l){
  lista *contador=(lista*)malloc(sizeof(lista));
  lista *anterior=NULL;
  for(contador=l;contador!=NULL;contador=contador->prox){
    if(contador->prox==NULL){
      break;
    }
    anterior=contador;
  }

  if(anterior==NULL){
    l=l->prox;
  }
  else{
    anterior->prox=contador->prox;
  }
  return l;
}

lista* lista_retira_busca(lista* l,int valor){
  lista *contador=(lista*)malloc(sizeof(lista));
  lista *anterior=NULL;
  for(contador=l;contador!=NULL;contador=contador->prox){
    if(contador->info==valor){
      break;
    }
    anterior=contador;
  }

  if(anterior==NULL){
    l=l->prox;
  }
  else if(contador==NULL){
    return l;
  }
  else{
    anterior->prox=contador->prox;
  }
  return l;
}

void lista_imprime(lista * l){
  lista *contador=(lista*)malloc(sizeof(lista));
  for(contador=l;contador!=NULL;contador=contador->prox){
    printf("%d\n",contador->info);
  }
  free(contador);
}

int main(){
  lista *l;
  l=lista_construtor();
  l=lista_insere(l,2);
  l=lista_insere(l,4);
  l=lista_insere(l,6);
  l=lista_insere(l,8);

  l=lista_retira_busca(l,4);
  l=lista_retira_inicio(l);
  l=lista_retira_fim(l);

  lista_imprime(l);

  return 0;
}

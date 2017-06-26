#include <stdlib.h>
#include <stdio.h>
#define MAX 10
//ESCREVA 10 ELEMENTOS EM UM VETOR E OS REMOVA IMPRIMINDO

int insereVetor();
void imprimeVetor(int vetor[]);
int main(){
    int vetor[10],i;
    for(i=0; i<MAX; i++){
      vetor[i] = insereVetor();
    }
    imprimeVetor(vetor);
    return 0;
}

int insereVetor(){
  int var;
  printf("INSIRA UM ELEMENTO NO VETOR: ");
  scanf("%d",&var);
  return var;
}

void imprimeVetor(int vetor[]){
  int i;
  for(i = 0; i<MAX; i++){
    printf("%d\n",vetor[i]);
  }
}

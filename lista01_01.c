#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float CalculaMedia(float *vetor);
float CalculaDP(float *vetor,float);

int main(){
  float *vetor[10],media,DP;
  int i;

  for(i=0;i<10;i++){
    printf("Insira o valor da posicao %d do vetor:",i);
    scanf("%f",&vetor[i]);
  }
    media=CalculaMedia(vetor);
    DP=CalculaDP(vetor,media);

    printf("O Desvio Padrao eh %f",DP);
  return 0;
}

float CalculaMedia(float *vetor){
    float media=0;
    int i;
    for(i=0;i<10;i++){
        media+=vetor[i];
        if(i==9){
            return (media/10);
        }
    }
  }
float CalculaDP(float *vetor,float media){
    int i;
    float soma=0;
    for(i=0;i<10;i++){
        vetor[i]= pow((vetor[i]-media),2);
        soma+=vetor[i];
        if(i==9){
            return sqrt(soma/10);
        }
    }

}

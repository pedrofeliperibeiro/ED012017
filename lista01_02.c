#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float CalculaMedia(float *vetor, int n);
float CalculaDP(float *vetor,float, int n);

int main(){
  int *vetor,n;
  float media,DP;
  int i;

  printf("Insira o tamanho do vetor:\n");
  scanf("%d",&n);
  vetor=(int *)malloc(n*sizeof(int));

  for(i=0;i<n;i++){
    vetor[i]=i;
  }
  printf("%d",n);

  for(i=0;i<n;i++){
    printf("Insira o valor da posicao %d do vetor:\n",i);
    scanf("%f",&vetor[i]);
  }
    media=CalculaMedia(vetor,n);
    DP=CalculaDP(vetor,media,n);

    printf("O Desvio Padrao eh %f\n",DP);

  return 0;
}

float CalculaMedia(float *vetor, int n){
    float media=0;
    int i;
    for(i=0;i<n;i++){
        media+=vetor[i];
        if(i==(n-1)){
            return (media/n);
        }
    }
  }
float CalculaDP(float *vetor,float media,int n){
    int i;
    float soma=0;
    for(i=0;i<n;i++){
        vetor[i]= pow((vetor[i]-media),2);
        soma+=vetor[i];
        if(i==(n-1)){
            return sqrt(soma/n);
        }
    }

}



#include <stdio.h>
#include <stdlib.h>

float CalculaMedia(int *vetor,int n);

int main(){

    int vetor[10];
    int i;

    for(i=0;i<10;i++){
        printf("Insira o elemento [%d] do vetor:\n",i);
        scanf("%d",&vetor[i]);
    }
    for(i=0;i<10;i++){
        printf("Vetor[%d]=%i\n",i,vetor[i]);
    }

    //-----------------------------------------
    //ALOCACAO DINAMICA
    int n,i;
    printf("Insira o numero de elementos a serem processados:\n");
    scanf("%d",&n);

    int *vetor=(int *)malloc(n*sizeof(int*));

    for(i=0;i<n;i++){
        printf("Insira o valor da posicao [%d] do vetor:\n",i);
        scanf("%d",&vetor[i]);
    }
    printf("A media eh: %.2f",CalculaMedia(vetor,n));
}

float CalculaMedia(int *vetor,int n){
    float media;
    int i;

    for(i=0;i<n;i++){
        media+=vetor[i];
    }
    return (media/n);
}

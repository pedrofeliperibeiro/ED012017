//CRIE UMA PILHA E EMPILHE DEZ VALORES E DESEMPILHE-OS IMPRIMINDO.
//LIFO - Last In, First Out.
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define tamanho 10

typedef struct stack{
    int topo;
    int conteudo[tamanho];
}pilha;

    pilha p;


void insereNaPilha(int);
int retiraDaPilha();

int main(){
    p.topo=0;
    int i;

    srand(time(NULL));

    printf("-----COLOCANDO NA PILHA-----\n");
    for(i=0;i<tamanho;i++){
        insereNaPilha(rand()%10);
        printf("PILHA[%d]=%d\n",i,p.conteudo[p.topo-1]);
    }
    printf("-----RETIRANDO DA PILHA-----\n");
    for(i=9;i>=0;i--){
        printf("PILHA[%d]=%d\n",i,retiraDaPilha());
    }
    return 0;
}

void insereNaPilha(int numero){
    p.conteudo[p.topo]=numero;
    p.topo+=1;
}
int retiraDaPilha(){
    p.topo-=1;
    int valor=p.conteudo[p.topo];
    return valor;
}

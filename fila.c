//CRIE UMA FILA E ADICIONE DEZ VALORES E REMOVA-OS IMPRIMINDO.
//FIFO - FIRST IN, FIRST OUT.
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define tamanho 10

typedef struct filas{
    int inicio;
    int fim;
    int conteudo[tamanho];
}fila;

    fila f;

void insereNaFila(int);
int retiraDaFila();

int main(){
    f.inicio=0;
    f.fim=0;
    int i;

    srand(time(NULL));

    printf("-----COLOCANDO NA FILA-----\n");
    for(i=0;i<tamanho;i++){
        insereNaFila(rand()%10);
        printf("FILA[%d]=%d\n",i,f.conteudo[f.fim-1]);
    }
    printf("-----RETIRANDO DA FILA-----\n");
    for(i=0;i<tamanho;i++){
        printf("FILA[%d]=%d\n",i,retiraDaFila());
    }
    return 0;
}

void insereNaFila(int numero){
    f.conteudo[f.fim]=numero;
    f.fim+=1;
}
int retiraDaFila(){
    int valor=f.conteudo[f.inicio];
    f.inicio+=1;
    return valor;
}

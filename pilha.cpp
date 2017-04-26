//CRIE UMA PILHA E EMPILHE DEZ VALORES E DESEMPILHE-OS IMPRIMINDO.
//LIFO - Last In, First Out.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//BIBLIOTECAS

#define MAX 10
//DEFININDO O TAMANHO MAXIMO DA PILHA ESTATICA

typedef struct{
    int conteudo[MAX];
    int topo;
}pilha;
//CRIANDO ESTRUTURA DA PILHA

pilha p;
//CRIANDO UMA ESTRUTURA DO TIPO "PILHA"

void pilha_construtor(){
    p.topo= -1;
}
// FUNCAO QUE INICIA A PILHA
// OBS: O TOPO EH (-1) POIS
// ZERO(0) EH UMA POSICAO VALIDA EM UM VETOR

bool pilha_vazia(){
    if(p.topo==-1){
        return true;
    }
    else{
        return false;
    }
}
//VERIFICA SE A PILHA ESTA VAZIA

int pilha_tamanho(){
    return p.topo+1;
}
//RETORNA A POSICAO DO TOPO DA PILHA
//OBS: (TOPO +1) POIS A PILHA INICIA NA POSICAO (-1)

bool pilha_cheia(){
    if(p.topo==(MAX-1)){
        return true;
    }
    else{
        return false;
    }
}
//VERIFICA SE A PILHA ESTA CHEIA


bool pilha_push(int valor){
    if (pilha_cheia()){
        return false;
    }
    else{
        p.topo++;
        p.conteudo[p.topo]= valor;
        return true;
    }
}
//PUSH INSERE NA PILHA

bool pilha_pop(int &valor){
    if(pilha_vazia()){
        return false;
    }
    else{
        valor=p.conteudo[p.topo];
        p.topo--;
        return true;
    }
}
//POP TIRA DA PILHA

bool pilha_get(int &valor){
    if(!pilha_vazia()){
        return false;
    }
    else{
        valor=p.conteudo[p.topo];
        return true;
    }
}
//PEGA O VALOR QUE SE ENCONTRA NO TOPO

int main(){

    int valor;
    srand(time(NULL));

    pilha_construtor();
    //INICIANDO A FILA

    while(pilha_push(rand() %10));

    printf("\nQUANTIDADE DE ITENS NA PILHA: %d \n",pilha_tamanho());

    while(pilha_pop(valor)){
        printf("\n %d \n",valor);
    }
    return 0;
}

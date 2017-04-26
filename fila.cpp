//CRIE UMA FILA E ADICIONE DEZ VALORES E REMOVA-OS IMPRIMINDO.
//FIFO - FIRST IN, FIRST OUT.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct{
    int frente;
    int tras;
    int conteudo[MAX];
}fila;

fila f;
void fila_construtor();
bool fila_vazia();
bool fila_cheia();
bool fila_aloca(int valor);
bool fila_retira(int &valor);
int  fila_get();

int main(){
    int valor,i=0;
    srand(time(NULL));

    fila_construtor();
    //INICIANDO A FILA

    while(fila_aloca(rand() %10));
    //ALOCANDO VALORES

    while(fila_retira(valor)){
        printf("VALOR NA FILA %d\n",valor);
    }
    //RETIRANDO E IMPRIMINDO VALORES
    return 0;
}

void fila_construtor(){
    f.frente=0;
    f.tras=-1;
}

bool fila_vazia(){
    if(f.frente>f.tras){
        return true;
    }
    else{
        return false;
    }
}

bool fila_cheia(){
    if(f.tras==(MAX-1)){
        return true;
    }
    else{
        return false;
    }
}

bool fila_aloca(int valor){
    if(fila_cheia()){
        return false;
    }
    else{
        f.tras++;
        f.conteudo[f.tras]=valor;
        return true;
    }
}

bool fila_retira(int &valor){
    if(fila_vazia()){
        return false;
    }
    else{
        valor=f.conteudo[f.frente];
        f.frente++;
        return true;
    }
}

int fila_get(int &valor){
    if(fila_vazia()){
        return false;
    }
    else{
        valor=f.conteudo[f.frente];
        return true;
    }
}


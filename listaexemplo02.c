#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

struct lista{
    char nome[20];
    char endereco[20];
    char telefone[20];
    struct lista *prox;

    /*APONTA PARA A PROXIMA ESTRUTURA*/
};

typedef struct lista Lista;
/*CRIANDO UMA ESTRUTURA DO TIPO LISTA*/

Lista* lista_construtor(){
    return NULL;
    /*PREENCHE COM NULL A LISTA*/
}

Lista* lista_insere(Lista* l,char nom[],char end[],char tel[]){
    Lista* novo=(Lista*) malloc(sizeof(Lista));
    strcpy(novo->nome,nom);
    strcpy(novo->endereco,end);
    strcpy(novo->telefone,tel);
    novo->prox= l;
    return novo;
}

void lista_imprime(Lista* l){
    Lista* p;
    /*CONTADOR*/
    for(p = l; p != NULL; p = p->prox){
        printf("Nome:%s\n",p->nome);
        printf("End:%s\n",p->endereco);
        printf("Tel:%s\n",p->telefone);
        printf("---------------\n");
    }
}

int lista_vazia(Lista* l){
    if(l== NULL){
        return true;
    }
    else{
        return false;
    }
}

Lista* lista_busca(Lista* l, char nom[]){
    Lista *p;
    for(p = l; p != NULL; p=p->prox){
        if(!strcmp(p->nome,nom)){
            printf("---------------\n");
            printf("Nome:%s\n",p->nome);
            printf("End:%s\n",p->endereco);
            printf("Tel:%s\n",p->telefone);
            printf("---------------\n");
            return p;
        }
    }
    return NULL;
}

Lista* lista_retira(Lista* l, char nom[]){
    Lista *anterior=NULL;
    Lista *p= l;

    while(p!=NULL && strcmp(p->nome,nom)){
      anterior=p;
      p= p->prox;
    }

    if(p==NULL){
        return l;
        /*SE CHEGAR AO FIM DA LISTA/NAO ACHOU...*/
    }
    else if(anterior == NULL){
        l=p->prox;
        /*RETIRA DO INICIO*/
    }
    else{
        anterior->prox = p->prox;
        /*RETIRA DO MEIO*/
    }
    free(p);
    return l;
}

void lista_libera(Lista *l){
    Lista *p=l;
    while(p!=NULL){
        Lista *t=p->prox;
        free(p);
        p=t;
    }
}

/*INSERE ORDENADO*/
Lista* lista_cria(char nom[],char end[],char tel[]){
    Lista *p=(Lista*)malloc(sizeof(Lista));
    /*p->info=v;*/
    strcpy(p->nome,nom);
    strcpy(p->endereco,end);
    strcpy(p->telefone,tel);
    return p;
}

Lista* lista_insere_ordenado(Lista *l,char nom[],char end[],char tel[]){
    Lista *novo=lista_cria(nom,end,tel);
    Lista *ant=NULL;
    Lista *p=l;

    while(p!=NULL && p->nome[0]<nom[0]){
        ant=p;
        p=p->prox;
    }

    if(ant==NULL){
        novo->prox=l;
        l=novo;
    }
    else{
        novo->prox=ant->prox;
        ant->prox=novo;
    }
    return l;
}

void menu(Lista* l){
    int valor;
    char nome[20], end[20], tel[20];
    printf("\n");
    printf("LISTA DE ENDERECOS:\n");
    printf("ADICIONAR -> (1)\n");
    printf("REMOVER   -> (2)\n");
    printf("BUSCAR    -> (3)\n");
    printf("LISTAR    -> (4)\n");

    scanf("%d",&valor);
    switch(valor){
        case 1:
            printf("NOME: ");
            scanf("%s",&nome);
            printf("ENDERECO: ");
            scanf("%s",&end);
            printf("TELEFONE: ");
            scanf("%s",&tel);
            l=lista_insere_ordenado(l,nome,end,tel);
            menu(l);
        break;
        case 2:
            if(!lista_vazia(l)){
                printf("INFORME A PESSOA QUE DESEJA REMOVER: \n");
                scanf("%s",&nome);
                l=lista_retira(l,nome);
            }
            else{
                printf("NENHUMA PESSOA CADASTRADA! \n");
            }
            menu(l);
        break;
        case 3:
            if(!lista_vazia(l)){
                printf("INFORME A PESSOA QUE DESEJA BUSCAR: \n");
                scanf("%s",&nome);
                l=lista_busca(l,nome);
            }
            else{
                printf("NENHUMA PESSOA CADASTRADA! \n");
            }
            menu(l);
        break;
        case 4:
            if(!lista_vazia(l)){
                printf("--------------------\n");
                printf("PESSOAS CADASTRADAS: \n");
                lista_imprime(l);
                menu(l);
            }
            else{
               printf("NENHUMA PESSOA CADASTRADA! \n");
               menu(l);
            }
        break;
        default:
        break;
    }
}

int main(){
    Lista* l;
    l=lista_construtor();
    menu(l);
    lista_libera(l);
    return 0;
}

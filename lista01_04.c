#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int i,j,**matriz;
    int linha,coluna,linhaColuna;
    int tamanho1,tamanho2;
    srand(time(NULL));

    printf("Insira a quantidade de linhas da Matriz:\n");
    scanf("%d",&linha);
    printf("Insira a quantidade de colunas da Matriz:\n");
    scanf("%d",&coluna);

    matriz=(int **)malloc(linha * sizeof(int*));

    for(i=0;i<linha;i++){
        matriz[i]=(int*)malloc(coluna * sizeof(int));
        for(j=0;j<coluna;j++){
            matriz[i][j]=rand()%100;

            printf("Matriz[%d][%d]=%d\n",i,j,matriz[i][j]);
        }
    }
    
    free(matriz);
    return 0;
}

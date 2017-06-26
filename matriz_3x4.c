#include <stdlib.h>
#include <stdio.h>
int matriz[3][4];

//INSIRA ELEMENTOS EM UMA MATRIZ 3 X 4 E OS IMPRIMA....
void insereMatriz(int, int);
void imprimeMatriz();

int main(){
    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<4; j++){
            insereMatriz(i,j);
        }
    }
    imprimeMatriz();
    return 0;
}

void insereMatriz(int i, int j){
  int var;
  printf("INSIRA UM ELEMENTO NA MATRIZ: ");
  scanf("%d",&var);
  matriz[i][j] = var;
}

void imprimeMatriz(){
  int i,j;
  for(i=0; i<3; i++){
      for(j=0; j<4; j++){
          printf("%d\n",matriz[i][j]);
      }
  }
}

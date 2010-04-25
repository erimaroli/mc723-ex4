#include <stdio.h>

#define TAM_MATRIZ 100

int main(int argc, char *argv[]){
  
  double matriz1[TAM_MATRIZ][TAM_MATRIZ];
  double matriz2[TAM_MATRIZ][TAM_MATRIZ];
  double matrizRes[TAM_MATRIZ][TAM_MATRIZ];
  int i, j, k;
  
  for(i=0; i<TAM_MATRIZ; i++){
    for(j=0; j < TAM_MATRIZ; j++){
      matriz1[i][j] = i + j;
      matriz2[i][j] = i + j;
    }
  }
  
  for(i=0; i<TAM_MATRIZ; i++){
    for(j=0; j < TAM_MATRIZ; j++){
      for(k = 0; k < TAM_MATRIZ; k++){
      matrizRes[i][j] += matriz1[i][k] * matriz2[k][j];
      }
    }
  }

  exit(0); // To avoid cross-compiler exit routine
  return 0; // Never executed, just for compatibility
}


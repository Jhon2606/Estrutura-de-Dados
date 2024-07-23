#include <stdio.h>
#include <stdlib.h>

int** transposta(int m, int n, int** mat);

int main(){

  int **M, i, j, m = 3, n = 3, **Q;

  M = (int **)malloc(m * sizeof(int*));
  for(i = 0; i < m; i++){
    M[i] = (int*)malloc(n * sizeof(int));
  }

  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      printf("Digite um numero:\n");
      scanf("%d", &M[i][j]);
    }
  }

  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  Q = transposta(m, n, M);

  for(i = 0; i < n; i++){
    for(j = 0; j < m; j++){
      printf("%d ", Q[i][j]);
    }
    printf("\n");
  }

  for(i = 0; i < n; i++){
    free(Q[i]);
  }
  free(Q);
  for(i = 0; i < m; i++){
    free(M[i]);
  }
  free(M);

  return 0;
}

int** transposta(int m, int n, int** mat){

  int i, j, **mat1;

  mat1 = (int **) malloc(n * sizeof(int*));
  for(i = 0; i < n; i++){
    mat1[i] = (int *) malloc(m * sizeof(int));
  }

  for(i=0; i < m; i++){
    for(j=0; j < n; j++){
      mat1[j][i] = mat[i][j];
    }
  }
  return mat1;
}
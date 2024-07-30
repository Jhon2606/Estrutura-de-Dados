#include <stdio.h>
#include <stdlib.h>

#define cad 80
#define num 3

typedef struct aluno{
  char nome[cad];
  int matricula;
}Aluno;

void inicializa (int n, Aluno **tab);
void leAluno (int n, Aluno **tab, int i);
void imprimeAluno(int n, Aluno** tab, int i);
void retiraAluno(int n, Aluno** tab, int i);

int main(){

  int i;
  Aluno *tab[num];

  inicializa(num, tab);
  leAluno(num, tab, i);
  imprimeAluno(num, tab, i);
  printf("Digite a posicão do auno que deseja remover:\n");
  scanf("%d", &i);
  retiraAluno(num, tab, i);

  i = 0;
  for(i = 0; i < num; i++){
    free(tab[i]);
  }

  return 0;
}

void inicializa (int n, Aluno **tab){

  int i;

  for(i = 0; i < n; i++){
    tab[i] = NULL;
  }

}

void leAluno (int n, Aluno **tab, int i){
  for(i = 0; i < n; i++){
    tab[i] = (Aluno *)malloc(sizeof(Aluno));
  }
  for(i = 0; i < n; i++){
    printf("Digite o nome do aluno:\n");
    scanf("%s", tab[i]->nome);
    printf("Digite a matricula do aluno:\n");
    scanf("%d", &tab[i]->matricula);
  }
}

void imprimeAluno(int n, Aluno** tab, int i){
  for(i = 0; i < n; i++){
    printf("Aluno: %s\n", tab[i]->nome);
    printf("Matricula: %d\n", tab[i]->matricula);
  }
}

void retiraAluno(int n, Aluno** tab, int i){

  int j;
  if (i < 0 || i >= n) {
  printf("Índice inválido.\n");
  return;
  }
  free(tab[i]);

  for(j = i; j < n - 1; j++){
    tab[j] = tab[j + 1];
  }
  tab[n - 1] = NULL;  
}
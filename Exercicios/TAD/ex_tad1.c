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
void imprime_tudo(int n, Aluno** tab);

int main(){

  int i;
  Aluno *tab[num];

  inicializa(num, tab);
  printf("Digite a posicao do auno que deseja adicionar:\n");
  scanf("%d", &i);
  leAluno(num, tab, i);
  printf("Digite a posicao do auno que deseja imprimir:\n");
  scanf("%d", &i);
  imprimeAluno(num, tab, i);
  printf("Digite a posicao do auno que deseja remover:\n");
  scanf("%d", &i);
  retiraAluno(num, tab, i);
  imprime_tudo(num, tab);

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

  tab[i] = (Aluno *)malloc(sizeof(Aluno));
  printf("Digite o nome do aluno:\n");
  scanf("%s", tab[i]->nome);
  printf("Digite a matricula do aluno:\n");
  scanf("%d", &tab[i]->matricula);
}

void imprimeAluno(int n, Aluno** tab, int i){
  if(tab[i] != NULL){
  printf("Aluno: %s\n", tab[i]->nome);
  printf("Matricula: %d\n", tab[i]->matricula);
  }
  else{
    printf("Campo não registrado.\n");
  }
}

void retiraAluno(int n, Aluno** tab, int i){

  int j;
  if (i < 0 || i >= n) {
  printf("Indice invalido.\n");
  return;
  }
  free(tab[i]);

  for(j = i; j < n - 1; j++){
    tab[j] = tab[j + 1];
  }
  tab[n - 1] = NULL;  
}

void imprime_tudo(int n, Aluno** tab){
  
  int i;

  for(i = 0; i < n; i++){
    printf("Aluno: %s\n", tab[i]->nome);
    printf("Matricula: %d\n", tab[i]->matricula);
  }
}

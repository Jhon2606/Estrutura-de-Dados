#include <stdio.h>
#include <stdlib.h>

#define cad 80
#define num 3

typedef struct aluno{
  char nome[cad];
  int matricula;
}Aluno;

void inicializa (int n, Aluno **tab);

int main(){

  int i;
  Aluno *tab[num];
  inicializa(num, tab);

  for(i = 0; i < num; i++){
    if (tab[i] == NULL) {
      printf("tab[%d] e NULL\n", i);
    } else {
      printf("tab[%d] não e NULL\n", i);
    }
  }

  for(i = 0; i < num; i++){
    free(tab[i]);
  }

  return 0;
}
void inicializa (int n, Aluno **tab){

  int i;

  for(i = 0; i < n; i++){
    tab[i] = (Aluno *)malloc(sizeof(Aluno));
  }
  for(i = 0; i < n; i++){
    tab[i] = NULL;
  }

}
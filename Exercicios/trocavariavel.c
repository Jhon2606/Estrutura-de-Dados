#include <stdio.h>
#include <stdlib.h>

void troca(int *i, int *j);

int main(){

  int *a, *b;

  printf("Digite dois valores:\n");
  scanf("%d %d", &a, &b);

  printf("As variaveis sem troca sao primeiro %d e segundo %d\n", a, b);

  troca(&a, &b);

  printf("As variaveis trocadas sao primeiro %d e depois %d\n", a, b);

  return 0;
}

void troca(int *i, int *j){

  int c;

  c = *i;
  *i = *j;
  *j = c;
}
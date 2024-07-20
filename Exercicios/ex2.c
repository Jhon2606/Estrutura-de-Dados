#include <stdio.h>
#include <stdlib.h>

int soma_impares(int n){

  return (n - 1) + (n + 1);

}

int main(){

  int n;

  printf("Digite um numero para saber a soma dos N primeiros numeros naturais impares:\n");
  scanf("%d", &n);

  printf("A soma dos n primeiros numeros naturais impares e: %d\n", soma_impares(n));
  
  return 0;
}
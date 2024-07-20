#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double pi(int n){

  int i;
  double num = 0;
  
  for(i = 0; i < n; i++){
      num += 4 * (pow(-1.0, i))/(2.0*i+1);

  }
  return num;
}

int main(){

  int n;

  printf("Digite o numero de valores que devem ser usados para avaliar o valor de PI:\n");
  scanf("%d", &n);

  printf("O valor de PI e aproximadamente %lf", pi(n));
  
  return 0;
}
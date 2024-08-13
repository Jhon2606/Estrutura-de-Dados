#include <stdio.h>
#include <stdlib.h>

int potencia(int x, int y);

int main(){

int n, m, p;

  printf("Digitte um numero:\n");
  scanf("%d", &n);
  printf("Digite sua potencia:\n");
  scanf("%d", &m);

  p = potencia(n, m);
  printf("A potencia e: %d", p);

  return 0;
}

int potencia(int x, int y){

  if(y == 0){
    return 1;
  }
  else{
    return x * potencia(x, y - 1);
  }

}
#include <stdio.h>
#include <stdlib.h>

int SomaSerie(int i,int j, int k);

int main(){

  int n, p, q, a;
  
  printf("Digite o intervalo:\n");
  scanf("%d %d", &n, &p);

  printf("Digite o incremento:\n");
  scanf("%d", &q);

  a = SomaSerie(n, p, q);
  printf("A soma da serie e: %d", a);

  return 0;
}

int SomaSerie(int i,int j, int k){
  
  if(i > j){
    return 0;
  }
  else{
    return i + SomaSerie(i + k, j, k);
  }

}
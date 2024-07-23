#include <stdio.h>
#include <stdlib.h>

int primo(int n);

int main(){

  int n;

  printf("Digite um numero para saber se o mesmo e primo:\n");
  scanf("%d", &n);

  if(primo(n)){
      printf("O numero e primo");
  }
  else{
    printf("O numero nao e primo");
  }

  return 0;
}

int primo(int n){

int i, r;

if(n <= 1){
  return 0;
}

for(i = 2; i < n; i++){

  if(n % i == 0){
    return 0;
  }
}

return 1;

}
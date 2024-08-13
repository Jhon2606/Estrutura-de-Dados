#include <stdio.h>
#include <stdlib.h>

typedef struct{

  int x, y;

} Ponto;

int dentro_ret(Ponto *ie, Ponto *sd, Ponto *p);

int main(){

Ponto ie, sd, p;

printf("Digite as coordenadas no veritice inferior esquerdo:\n");
scanf("%d %d", &ie.x, &ie.y);

printf("Digite as coordenadas no veritice superior direito:\n");
scanf("%d %d", &sd.x, &sd.y);

printf("Digite as coordenadas do ponto a ser verificado:\n");
scanf("%d %d", &p.x, &p.y);

if(dentro_ret(&ie, &sd, &p)){
  printf("O ponto esta dentro do retangulo.\n");
}
else{
  printf("O ponto esta fora do retangulo.\n");
}
return 0;
}

int dentro_ret(Ponto *ie, Ponto *sd, Ponto *p){
  if (p->x >= ie->x && p->x <= sd->x && p->y >= ie->y && p->y <= sd->y) {
      return 1;
  } 
  else {
      return 0;
  }
}
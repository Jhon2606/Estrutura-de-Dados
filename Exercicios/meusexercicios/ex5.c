#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
  float info;
  struct nolista* prox;
}Nolista;

typedef struct fila{
  Nolista* ini, *fim;
}Fila;

Fila* CriarFila(){
  Fila* f = (Fila*)malloc(sizeof(Fila));
  if(f!=NULL){
    f->ini = f->fim = NULL;
    return f;
  }else{
    printf("Espaco nao alocado.\n");
    return NULL;
  }
}

int EstaVazia(Fila* f){
  return(f->ini == NULL);
}

void inserir(Fila* f, float v){
  Nolista* novo = (Nolista*)malloc(sizeof(Nolista));
  if(novo!=NULL){
    novo->info = v;
    novo->prox = NULL;
    if(!EstaVazia(f)){
      f->fim->prox = novo;
    }else{
      f->ini = novo;
    }
    f->fim = novo;
  }else{
    printf("Espaco nao alocado.\n");
  }
}

void imprimeFila(Fila* f){
  Nolista* p;
  if(!EstaVazia(f)){
    for(p = f->ini;p!=NULL; p = p->prox){
    printf("[%.1f]", p->info);
  }
  }else{
    printf("Fila vazia.\n");
  }
}

float remover(Fila* f){
  if(!EstaVazia(f)){
    Nolista* p = f->ini;
    f->ini = p->prox;
    if(f->ini == NULL){
      f->fim = NULL;
    }
    float v = p->info;
    free(p);
    return v;
  }else{
    printf("Fila vazia.\n");
  }
}

float primeiro(Fila* f){
  if(!EstaVazia(f)){
    return f->ini->info;
  }else{
    printf("A fila esta vazia.\n");
  }
}

void LiberarFila(Fila* f){
  Nolista* p, *temp;
    for(p = f->ini;p != NULL;p = temp){
    temp = p->prox;
    free(p);
  }
  free(f);
}

float maior(Fila* f){
  Nolista* p;
  if(!EstaVazia(f)){
    float num = f->ini->info;
  for(p = f->ini; p != NULL; p = p->prox){
    if(p->info > num){
      num = p->info;
    }
  }
  return num;
  }else{
  printf("Fila vazia.\n");
  return 0;
  }
}

void CombinaFilas(Fila* f_res, Fila* f1, Fila* f2){
    while(!EstaVazia(f1) || !EstaVazia(f2)){
        if(!EstaVazia(f1)){
        inserir(f_res, f1->ini->info);
        remover(f1);
        }
        if(!EstaVazia(f2)){
        inserir(f_res, f2->ini->info);
        remover(f2);
        }
    }
}

void CombinaFilasRec(Fila* f_res, Fila* f1, Fila* f2){
    if (EstaVazia(f1) && EstaVazia(f2)) {
        return;
    }
    if (!EstaVazia(f1)) {
        inserir(f_res, f1->ini->info);
        remover(f1);
    }

    if (!EstaVazia(f2)) {
        inserir(f_res, f2->ini->info);
        remover(f2);
    }
    CombinaFilasRec(f_res, f1, f2);

}

int main(){
  Fila* fila = CriarFila();
  Fila* filacomb = CriarFila();
  Fila* fila2 = CriarFila();
  inserir(fila, 1);
  inserir(fila, 2);
  inserir(fila, 3);
  imprimeFila(fila);
  printf("\n");
  inserir(fila2, 4);
  inserir(fila2, 5);
  inserir(fila2, 6);
  imprimeFila(fila2);
  printf("\n");
  CombinaFilasRec(filacomb, fila, fila2);
  imprimeFila(filacomb);
  printf("\n");
  return 0;
}

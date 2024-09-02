#include <stdio.h>
#include<stdlib.h>

typedef struct nolista{
  float info;
  struct nolista* prox;
}Nolista;

typedef struct pilha{
  struct nolista* prim;
}Pilha;

Pilha* CriarPilha(){
  Pilha* p = (Pilha*)malloc(sizeof(Pilha));
  if(p != NULL){
    p->prim = NULL;
    return p;
  }
}

int EstaVazia(Pilha* p){
  return(p->prim == NULL);
}

void Push(Pilha* p, float v){
  Nolista* novo = (Nolista*)malloc(sizeof(Nolista));
  if(novo!=NULL){
    novo->info = v;
    novo->prox = p->prim;
    p->prim = novo;
  }else{
    printf("Espaco nao alocado.\n");
  }
}

void imprimePilha(Pilha* p){
  Nolista* i;
  if(!EstaVazia(p)){
    for(i = p->prim; p != NULL; i = i->prox){
      printf("[%.1f]", i->info);
    }
  }else{
    printf("Lista vazia.\n");
  }
}

float Pop(Pilha* p){
  Nolista* t;
  float v;
  if(!EstaVazia(p)){
    t = p->prim;
    p->prim = t->prox;
    v = t->info;
    free(t);
    return v;
  }else{
    printf("A lista esta vazia.\n");
  }
}

void LiberarPilha(Pilha* p){
  Nolista* i, *temp;
  if(!EstaVazia(p)){
    for(i = p->prim; i != NULL; i = temp){
    temp = i->prox;
    free(i);
    }
  free(p);
  }
}

float VerTopo(Pilha* p){
  if(!EstaVazia(p)){
    return p->prim->info;
  }else{
    printf("A lista esta vazia.\n");
  }
}

int main(){
  Pilha* pilha = CriarPilha();
  Push(pilha, 1);
  Push(pilha, 2);
  Push(pilha, 3);
  imprimePilha(pilha);
  return 0;
}
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

void Linha(){
    printf("\n--------------------\n");
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

void ConcatenaPilhas(Pilha* p1, Pilha* p2){
    Pilha* i, *temp = CriarPilha();
    while(!EstaVazia(p2)){
        Push(temp, Pop(p2));
    }
    while (!EstaVazia(temp)){
        Push(p1,  Pop(temp));
    }
    Liberarpilha(temp);
}

void concatenarecursiva(Pilha* p1, Pilha* p2){
    if(EstaVazia(p2)){
        return;
    }
    float valor = Pop(p2);
    concatenarecursiva(p1, p2);
    Push(p1, valor);
}

void ConcatenaSemTAD(Pilha* p1, Pilha* p2) {
    Nolista* i;
    Pilha* pilhaaux = CriarPilha();
    while (!EstaVazia(p2)) {
        i = p2->prim;
        p2->prim = i->prox;
        i->prox = pilhaaux->prim;
        pilhaaux->prim = i;
    }
    while (!EstaVazia(pilhaaux)) {
        i = pilhaaux->prim;
        pilhaaux->prim = i->prox;
        i->prox = p1->prim;
        p1->prim = i;
    }
    free(pilhaaux);
}

int main(){
    Pilha* pilha = CriarPilha();
    Pilha* pilha2 = CriarPilha();
    Linha();
    Push(pilha, 1);
    Push(pilha, 2);
    Push(pilha, 3);
    ImprimePilha(pilha);
    Linha();
    Push(pilha2, 4);
    Push(pilha2, 5);
    Push(pilha2, 6);
    ImprimePilha(pilha2);
    Linha();
    ConcatenaSemTAD(pilha, pilha2);
    ImprimePilha(pilha);
  return 0;
}

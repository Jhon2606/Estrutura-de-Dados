#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
    float info;
    struct nolista* prox;
}Nolista;

typedef struct pilha{
    struct nolista* prim;
}Pilha;

Pilha* CriarPilha(){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
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
}
else{
    printf("Espaco nao alocao.\n");
}
}

//A funcao de impressao e so para teste, normalmente nao usamos a impressao na pilha

void ImprimePilha(Pilha* p){
    Nolista* i;
    if(!EstaVazia(p)){
        for(i = p->prim; i != NULL; i = i->prox){
            printf("[%.1f] ", i->info);
        }
    }
    else{
        printf("A lista esta vazia.\n");
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
    }
    else{
        printf("A lista esta vazia.\n");
    }
}

void Liberarpilha(Pilha* p){
    Nolista* t, *temp;
    if(!EstaVazia(p)){ 
        for(t = p->prim; p != NULL; t = temp){
            temp = t->prox;
            free(t);
        }
    }
    else{
        printf("A lista esta vazia.\n");
    }
    free(p);
}

float VerTopo(Pilha* p){
    float a;
    Nolista* t;
    if(!EstaVazia(p)){
        return p->prim->info;
    }
    else{
        printf("A lista esta vazia.\n");
    }
}

int comparapilha(Pilha* p1, Pilha* p2){
  Nolista* p, *q;
  if((!EstaVazia(p1)) && !EstaVazia(p2)){
    for(p = p1->prim, q = p2->prim; p != NULL, q !=NULL; p = p->prox, q = q->prox){
      if(p->info != q->info){
        return 0;
      }
    }
    if(p != NULL || q != NULL)
    return 0; 
  }
  return 1;
}



int main(){
    Pilha* pilha = CriarPilha();
    Push(pilha, 1);
    Push(pilha, 2);
    Push(pilha, 3);
    Pilha* p2 = CriarPilha();
    Push(p2, 1);
    Push(p2, 2);
    Push(p2, 3);
    ImprimePilha(pilha);
    int i = comparapilha(pilha, p2);
    printf("%d", i);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
    float info;
    struct nolista* prox;
}Nolista;

typedef struct pilha{
    struct Nolista* prim;
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
        for(t = p->prim; p != NULL; t =  temp){
            temp = t ->prox;
            free(t);
        }
    }
    else{
        printf("A lista esta vazia.\n");
    }
    free(p);
}

int main(){
    Pilha* pilha = CriarPilha();
    Push(pilha, 3.5);
    Push(pilha, 3.2);
    Push(pilha, 3.3);
    ImprimePilha(pilha);
    return 0;
}
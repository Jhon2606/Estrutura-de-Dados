#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
    int info;
    struct nolista* prox;
}Nolista;

void criarLista(Nolista** l){
    *l = NULL;
}

int estaVazia(Nolista** l){
    return(*l == NULL);
}

void insereElemento(Nolista** l, int v){
    Nolista* novo = (Nolista*)malloc(sizeof(Nolista));
    if(novo != NULL){
        novo -> info = v;
        novo -> prox = *l;
        *l = novo;
    }
    else{
        printf("Nao foi possivel alocar espaco\n");
        exit(1);
    }
}

void imprimeelementos(Nolista** l){
    if(!estaVazia(l)){
        for(Nolista* p = *l;p != NULL;p = p->prox){
            printf("%d\n", p->info);
        }
    }
    else{
        printf("A lista esta vazia!");
    }
}

Nolista* copia(Nolista** l) {
    Nolista* p, *novalista = NULL;

    for (p = *l; p != NULL; p = p->prox) {
        Nolista* novo = (Nolista*)malloc(sizeof(Nolista));
        if (novo != NULL) {
            novo->info = p->info;
            novo->prox = novalista;
            novalista = novo;
        } else {
            printf("Espaco nao alocado\n");
            return NULL;
        }
    }

    Nolista* anterior = NULL;
    Nolista* atual = novalista;
    Nolista* proximo;

    for (; atual != NULL; atual = proximo) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
    }

    return anterior;
}

int main(){
    Nolista* lista;
    criarLista(&lista);
    insereElemento(&lista, 1);
    insereElemento(&lista, 2);
    insereElemento(&lista, 3);
    imprimeelementos(&lista);
    Nolista* lista2 = copia(&lista);
    printf("\n");
    imprimeelementos(&lista2);
    return 0;
}


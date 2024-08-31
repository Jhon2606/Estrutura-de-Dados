#include <stdio.h>
#include <stdlib.h>

typedef struct noLista {
    int info;
    struct noLista* prox;
    struct noLista* ant;
}NoLista;

NoLista* criarVazia() {
    NoLista* l = NULL;
    return l;
}

int estaVazia(NoLista** l) {
    return (*l == NULL);
}

void inserirElemento(NoLista** l, int v) {
    NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
    if (novo != NULL) {
        novo->info = v;
        novo->prox = *l;
        novo->ant = NULL;
        if (!estaVazia(l)) {
            (*l)->ant = novo;
        }
        *l = novo;
    }


}

void imprimeListaOrdemDireta(NoLista** l) {
    NoLista* p;
    if (!estaVazia(l)) {
        for (p = *l; p != NULL; p = p->prox) {
            printf("%d\n", p->info);
        }
    } else {
        printf("A lista esta vazia!\n");
    }
}

NoLista* ultimoElemento(NoLista** l){
    if(!estaVazia(l)) {
        NoLista* p;
        for (p = *l; p->prox != NULL; p = p->prox);
        return p;
    } else {
        return NULL;
    }
}

void imprimeListaOrdemInversa(NoLista** l) {
    if (!estaVazia(l)) {
        NoLista* p;
        for (p = ultimoElemento(l); p != NULL; p = p->ant) {
            printf("%d\n", p->info);
        }
    } else {
        printf("Lista vazia!\n");
    }
    
}

NoLista* buscaElemento(NoLista** l, int v) {
    NoLista* p;
    for (p = *l; p != NULL; p = p->prox) {
        if (p->info == v) {
            return p;
        }
    }

    return NULL;
}

void removerElemento(NoLista** l, int v) {
    NoLista* p = buscaElemento(l, v);
    if (p != NULL) {    
        if (*l == p)
            (*l) = p->prox;
        else
        p->ant->prox = p->prox;

        if (p->prox != NULL)
            p->prox->ant = p->ant;

        free(p);
    }
}

void liberarLista(NoLista** l) {
    NoLista* p, *temp;
    for (p = *l; p != NULL; p = temp) {
        temp = p->prox;
        free(p);
    }

    *l = NULL;
    
}

int main() {

    NoLista* lista = criarVazia();

    return 0;
}
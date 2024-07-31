#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
    int info;
    struct nolista* prox;
}Nolista;

void criarLista(Nolista** l);
int estaVazia(Nolista** l);
void insereElemento(Nolista** l, int v);
void imprimeelementos(Nolista** l);
Nolista* buscaElemento(Nolista** l, int v);
void removeelemento(Nolista** l, int v);

int main(){
    Nolista* lista;
    criarLista(&lista);
    insereElemento(&lista, 1);
    insereElemento(&lista, 2);
    insereElemento(&lista, 3);
    imprimeelementos(&lista);
    buscaElemento(&lista, 2);
    removeelemento(&lista, 1);
    imprimeelementos(&lista);

    return 0;
}

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

Nolista* buscaElemento(Nolista** l, int v){
    if(!estaVazia(l)){
        for(Nolista* p = *l;p != NULL;p = p->prox){
            if(p->info == v){
                return p;
            }
        }
        return NULL;
    }
    else{
        printf("A lista esta vazia!");
    }
}

void removeelemento(Nolista** l, int v){
    Nolista* ant = NULL;
    Nolista* p = NULL;
    if(!estaVazia(l)){
        for(p = *l; p != NULL && p -> info != v; p = p -> prox){
            ant = p;
        }
            if(p == NULL){
                printf("Elemento nao encontrado.\n");
            }
            else{
                if(ant != NULL){
                    ant -> prox = p -> prox;
                }
                else{
                    *l = p -> prox;
                }
                free(p);
        }
    }
    else{
        printf("Lista vazia.\n");
    }
}
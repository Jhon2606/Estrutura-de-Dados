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
void liberarLista(Nolista** l);
void insereOrdenado(Nolista** l, int v);
int numElementos(Nolista** l);
Nolista* retpoint(Nolista** l, int v);
void imprimeOrdem(Nolista** l);

int main(){
    Nolista* lista;
    criarLista(&lista);
    //insereElemento(&lista, 1);
    //insereElemento(&lista, 2);
    //insereElemento(&lista, 3);
    insereOrdenado(&lista, 6);
    insereOrdenado(&lista, 5);
    insereOrdenado(&lista, 4);
    imprimeelementos(&lista);
    //buscaElemento(&lista, 2);
    //removeelemento(&lista, 1);
    //imprimeelementos(&lista);
    //liberarLista(&lista);
    printf("O numero de elementos na lista e %d\n", numElementos(&lista));
    Nolista* p = retpoint(&lista, numElementos(&lista));
    printf("%d\n", p -> info);
    printf("-------------\n");
    imprimeOrdem(&lista);

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

void liberarLista(Nolista** l){
    Nolista* p, *temp;
    for(p = *l;p != NULL;p = temp){
    temp = p-> prox;
    free(p);
    }
    *l = NULL;
}

void insereOrdenado(Nolista** l, int v){
    Nolista* p, *ant = NULL;
    Nolista* novo = (Nolista*)malloc(sizeof(Nolista));
    if(novo != NULL){
        novo -> info = v;
        for(p = *l; p != NULL && p -> info < v; p = p -> prox)
        ant = p;
    novo -> prox = p;
    if(ant == NULL){
        *l = novo;

    }
    else{
        ant -> prox = novo;
    }
}
else{
    printf("Nao foi possivel alocar espaco.\n");
}
}

int numElementos(Nolista** l){

    int i = 0;
    Nolista* p;
    for(p = *l; p!= NULL; p = p -> prox){
        i++;
    }
    return i;
}

Nolista* retpoint(Nolista** l, int v) {
    Nolista* p;
    for(p = *l; p != NULL; p = p->prox) {
        if (p->info == v) {
            return p;
        }
    }
    return NULL;
}

void ImprimeOrdem(Nolista** l){
  Nolista* p, *ant, *temp = NULL;
  if(!EstaVazia(l)){
    for(p = *l; p != NULL; p = p->prox){
    ant = p;
    }
  while(ant != NULL){
    printf("%d\n", ant->info);
    p = *l;
    temp = NULL;
    while (p != ant) {
      temp = p;
      p = p->prox;
    }
    ant = temp;
  }
}
  else{
    printf("Lista vazia.\n");
  }
}

#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
    int info;
    struct nolista* prox;
}Nolista;

typedef struct descritor{
    Nolista* prim, *ult;
    int n;
}Descritor;

Descritor criarLista();
int estaVazia(Descritor* l);
void inserirElementoInicio(Descritor* l, int v);
void imprimeLista(Descritor* l);
void InserirElementoFim(Descritor* l, int v);
void removeElemento(Descritor* l, int v);

int main(){
    Descritor lista = criarLista();
    inserirElementoInicio(&lista, 1);
    inserirElementoInicio(&lista, 2);
    inserirElementoInicio(&lista, 3);
    imprimeLista(&lista);
    return 0;
}

Descritor criarLista(){
    Descritor l;
    l.prim = l.ult = NULL;
    l.n = 0;
    return l;
}

int estaVazia(Descritor *l){
    return(l->n==0);
}

void inserirElementoInicio(Descritor* l, int v){
    Nolista* novo = (Nolista*)malloc(sizeof(Nolista));
    if(novo!=NULL){
        novo->info=v;
        novo->prox=l->prim;
        l->prim=novo;
                if(l->n==0){
            l->ult=novo;
        }
        l->n++;
    }
}

void imprimeLista(Descritor* l){
    Nolista* p;
    if(!(estaVazia(l))){
    for(p=l->prim;p!=NULL;p=p->prox)
        printf("%d\n", p->info);
    }
    else{
    printf("A lista esta vazia!\n");
    }
}

void InserirElementoFim(Descritor* l, int v){
    Nolista* novo = (Nolista*)malloc(sizeof(Nolista));
    if(novo!=NULL){
        novo->info=v;
        novo->prox=NULL;
        if(l->ult!=NULL){
            l->ult->prox=novo;
            l->ult=novo;
        }
        else{
            l->prim=novo;
            l->ult=novo;
        }
        l->n++;
    }
}

void removeElemento(Descritor*l, int v){
    Nolista* p, *ant = NULL;
    for(p=l->prim;p!=NULL&&p->info!= v;p=p->prox);
    ant=p;
    if(p==NULL){
    printf("Elemento nao encontrado.\n");
    }
    else{
        if(ant=NULL){
            l->prim=p->prox;
            if(l->prim==NULL){
                l->ult=NULL;

            }
        }
        else{
            ant->prox=p->prox;
            if(ant->prox==NULL){
                l->ult=ant;
            }
        }
        l->n--;
        free(p);
    }
}
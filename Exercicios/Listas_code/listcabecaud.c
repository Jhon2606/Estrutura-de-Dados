#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
    int info;
    struct nolista* prox;
}Nolista;

typedef struct lista{
    Nolista* cab;
    Nolista* cau;

}Lista;

Lista criarVazia();
int estaVazia(Lista* l);
void inserirElementoInicio(Lista* l, int v);
void imprimeLista(Lista* l);
void inserirElementoFim(Lista* l, int v);
void removeElemento(Lista* l, int v);
void LiberarLista(Lista* l);

int main(){
    Lista lista;
    lista = criarVazia();
    inserirElementoInicio(&lista, 1);
    inserirElementoInicio(&lista, 2);
    inserirElementoInicio(&lista, 3);
    imprimeLista(&lista);
    LiberarLista(&lista);
    return 0;
}

Lista criarVazia(){
    Lista l;
    l.cab = (Nolista*)malloc(sizeof(Nolista));
    l.cau = (Nolista*)malloc(sizeof(Nolista));
    l.cab->prox=l.cau;
    l.cau->prox=NULL;
    return l;
}

int estaVazia(Lista* l){
    return(l->cab->prox==l->cau);
}

void inserirElementoInicio(Lista* l, int v){
    Nolista* novo = (Nolista*)malloc(sizeof(Nolista));
    if(novo!=NULL){
        novo->info=v;
        novo->prox=l->cab->prox;
        l->cab->prox=novo;
    }
    else{
        printf("Nao foi possivel alocar espaco.\n");
    }
}

void imprimeLista(Lista* l){
    Nolista* p;
    if(!estaVazia(l)){
    for(p = l->cab->prox;p!=l->cau;p=p->prox){
        printf("%d\n", p->info);
    }
    }
    else{
        printf("Lista vazia\n");
    }
}

void inserirElementoFim(Lista* l, int v){
    Nolista* ult = l->cab;
    Nolista* novo = (Nolista*)malloc(sizeof(Nolista));
    if(novo!=NULL){
        novo->info=v;
        novo->prox=l->cau;
        for(;ult->prox!=l->cau;ult=ult->prox);
        ult->prox=novo;
    }
    else{
        printf("Espaco nao alocado\n");
    }
}

void removeElemento(Lista* l, int v){
    Nolista* ant = l->cab, *p;
    for(p=l->cab->prox; p!=l->cau&&p->info!=v; p=p->prox){
    ant=p;
    }
    if(p==l->cau){
        printf("Elemento nao encontrado!");
    }
    else{
        ant->prox = p->prox;
        free(p);
    }
}

void LiberarLista(Lista* l){
    Nolista* p, *temp;
    for(p = l;p != NULL;p = temp){
    temp = p-> prox;
    free(p);
    }
    l->cab->prox=l->cau;
}

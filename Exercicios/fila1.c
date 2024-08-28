#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
    float info;
    struct nolista* prox;
}Nolista;

typedef struct fila{
    Nolista* ini;
    Nolista* fim;
}Fila;

Fila* CriarFila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if(f != NULL){
    f->ini = f->fim = NULL;
    return f;
    }
    else{
        printf("Espaco nao alocado.\n");
        return NULL;
    }
}

int estaVazia(Fila* f){
    return(f->ini == NULL);
}

void inserir(Fila* f, float v){
    Nolista* novo = (Nolista*)malloc(sizeof(Nolista));
    if(novo!=NULL){
        novo->info = v;
        novo->prox = NULL;
        if(!estaVazia(f)){
            f->fim->prox = novo;
        }else{
            f->ini = novo;
        }
        f->fim = novo;
    }else{
        printf("Espaco nao alocado.\n");
    }
}
//A funcao de impressao e so para teste, normalmente nao usamos a impressao na fila
void imprimeFila(Fila* f){
    Nolista* p;
    if(!estaVazia(f)){
        for(p = f->ini; p!= NULL; p = p->prox){
        printf("[%.1f] ", p->info);
    }
    }else{
        printf("Lista vazia\n");
    }
}

float remover(Fila* f){
    if(!estaVazia(f)){
        Nolista* p = f->ini;
        f->ini = p->prox;
        if(f->ini == NULL){
            f->fim = NULL;
        }
        float v = p->info;
        free(p);
        return v;
    }else{
        printf("Fila vazia.\n");
    }
}

void LiberaFila(Fila* f){
    Nolista* p, *temp;
    for(p = f->ini; p!=NULL; p = temp){
        temp = p->prox;
        free(p);
    }
    free(f);
}

int main(){
    Fila* fila = CriarFila();
    inserir(fila, 1);
    inserir(fila, 2);
    inserir(fila, 3);
    imprimeFila(fila);

    return 0;
}

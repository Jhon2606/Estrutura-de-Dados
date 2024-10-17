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

float retornaPrimeiro(Fila* f){
    if(!estaVazia(f)){
        return f->ini->info;
    }
    else{
        printf("A fila esta vazia.\n");
    }
}

void FuraFila(Fila* f, float v){
    Nolista* p, *ant  = NULL;
    if(!estaVazia(f)){
        for(p = f->ini; p != NULL && p->info!= v; p = p->prox){
            ant = p;
        }
        if(p != NULL && p->info == v){
            if(ant != NULL){
            ant->prox = p->prox;
            p->prox = f->ini;
            f->ini = p;
        }else{
            printf("Este valor ja esta no inicio.\n");
        }
        }else{
            printf("Valor nao encontrado.\n");
        }
        
    }else{
        printf("Fila vazia.\n");
    }
}

void divideFila(Fila* f, Fila* f1, Fila* f2, int n){
  Nolista* p;
  if(!estaVazia(f)){
    for(p = f->ini; p!= NULL && p->info != n; p = p->prox);
    if(p->prox != NULL){
      f2->ini = p->prox;
      f2->fim = f->fim;
      f->fim = p;
      f->fim->prox = NULL;
      f1->ini = f->ini;
      f1->fim = f->fim;
    }
  }else{
    printf("Fila vazia.\n");
    return;
  }
}

int main(){
    Fila* fila = CriarFila();
    Fila* fila2 = CriarFila();
    Fila* fil = CriarFila();
    inserir(fil, 1);
    inserir(fil, 2);
    inserir(fil, 3);
    inserir(fil, 4);
    inserir(fil, 5);
    divideFila(fil, fila, fila2, 3);
    printf("\n");
    imprimeFila(fila);
    printf("\n");
    imprimeFila(fila2);
    return 0;
}

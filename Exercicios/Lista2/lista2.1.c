#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
  int info;
  struct nolista* prox;
}Nolista;

void CriarLista(Nolista** l);
int EstaVazia(Nolista** l);
void InsereElemento(Nolista** l, int i);
void imprimeRecursiva(Nolista** l);
void liberarLista(Nolista** l) ;
Nolista* buscaRecursiva(Nolista** l, int v);
void removerElemento(Nolista** l, int v);

int main(){
  Nolista* lista;
  CriarLista(&lista);
  InsereElemento(&lista, 1);
  InsereElemento(&lista, 2);
  InsereElemento(&lista, 3);
  imprimeRecursiva(&lista);
  //liberarLista(&lista);
  Nolista* resultado;
  resultado = buscaRecursiva(&lista, 2);
  if (resultado != NULL) {
    printf("Valor 2 encontrado na lista.\n");
  } 
  else {
    printf("Valor 2 nao encontrado na lista.\n");
  }
  removerElemento(&lista, 3);
  imprimeRecursiva(&lista);

  return 0;
}

void CriarLista(Nolista** l){
  *l = NULL;
}

int EstaVazia(Nolista** l){
  return(*l == NULL);
}

void InsereElemento(Nolista** l, int i){
  Nolista* temp = (Nolista*)malloc(sizeof(Nolista));
  if(temp!=NULL){
    temp->info = i;
    temp->prox = *l;
    *l = temp;
  }
  else{
    printf("Nao foi possivel alocar espaco.\n");
  }
}

void imprimeRecursiva(Nolista** l){
  if(*l==NULL){
    return;
  }
  imprimeRecursiva(&(*l)->prox);
  printf("%d\n", (*l)->info);
}

void liberarLista(Nolista** l) {
  Nolista* p = NULL, *temp = NULL;
  for(p=*l; p!=NULL;p=temp){
    temp = p->prox;
    free(p);
  }
  *l = NULL;
}

Nolista* buscaRecursiva(Nolista** l, int v){
 if(*l==NULL){
  return NULL;
 }
 if((*l)->info==v){
  return *l;
 }
 return buscaRecursiva(&(*l)->prox, v);
}

void removerElemento(Nolista** l, int v){
  Nolista* temp;
  if(*l==NULL){
    return NULL;
  }
  if((*l)->info == v){
    temp = *l;
    *l = (*l)->prox;
    free(temp);
    return;
  }
  removerElemento(&(*l)->prox, v);
}
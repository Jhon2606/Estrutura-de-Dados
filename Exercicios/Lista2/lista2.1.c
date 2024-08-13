#include <stdio.h>
#include <stdlib.h>

//TAD
typedef struct nolista{
  int info;
  struct nolista* prox;
}Nolista;

//Cabeçalho
void CriarLista(Nolista** l);
int EstaVazia(Nolista** l);
void InsereElemento(Nolista** l, int i);
void imprimir(Nolista** l);
Nolista* ultimo(Nolista** l);
int Maiores(Nolista** l, int i);
Nolista* concatena(Nolista** l, Nolista** l2);
Nolista* separa(Nolista** l, int n);

int main(){
  //Utilizando a lista1
  Nolista *Lista;
  CriarLista(&Lista);
  InsereElemento(&Lista, 5);
  InsereElemento(&Lista, 7);
  InsereElemento(&Lista, 3);
  InsereElemento(&Lista, 9);
  printf("Lista1:\n");
  imprimir(&Lista);
  printf("O ultimo ponteiro da lista e: %d\n", ultimo(&Lista)->info);
  printf("O numero de nos maiores que 2 sao %d\n", Maiores(&Lista, 2));

  //Utilizando a lista2
  Nolista *Lista2;
  CriarLista(&Lista2);
  InsereElemento(&Lista2, 1);
  InsereElemento(&Lista2, 2);
  InsereElemento(&Lista2, 4);
  printf("Lista2:\n");
  imprimir(&Lista2);

  //Utilizando as duas listas
  Nolista* listajunta, *listacort;
  //listajunta = concatena(&Lista, &Lista2);
  //printf("Lista concatenada:\n");
  //imprimir(&listajunta);
  listacort = separa(&Lista, 3);
  printf("Parte 1 da lista:\n");
  imprimir(&Lista);
  printf("Parte 2 da lista:\n");
  imprimir(&listacort);
  return 0;
}

//Funçoes
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

void imprimir(Nolista** l){
  Nolista* p;
  if(!EstaVazia(l)){
    for(p =  *l; p!=NULL; p=p->prox){
      printf("%d\n", p->info);
    }
  }
  else{
    printf("A lista esta vazia.\n");
  }
}

Nolista* ultimo(Nolista** l){
  Nolista* p = NULL, *temp = NULL;
  if(!EstaVazia(l)){
      for(p = *l; p!=NULL; p = p->prox){
        temp = p;
    }
  }
  else{
    printf("A lista esta vazia.\n");
  }
  return temp;
}

int Maiores(Nolista** l, int i){
  Nolista* p;
  int j = 0;
  if(!EstaVazia(l)){
      for(p = *l; p!=NULL; p=p->prox){
        if(p->info > i){
          j++;
        }
    }
  }
  else{
    printf("A lista esta vazia.\n");
  }
    return j;
}

Nolista* concatena(Nolista** l, Nolista** l2){
  Nolista *p = NULL;
  if(EstaVazia(l) || EstaVazia(l2)){
    printf("Nao existem duas duas listas a serem concatenadas.\n");
    return *l;
  }
  else{
    for(p =*l; p->prox!=NULL; p=p->prox);
    p->prox = *l2;
  }
  return *l;
}
//Separa a lista ate o valor indicado e cira outra lista de onde parou
Nolista* separa(Nolista** l, int n){
  Nolista* p=NULL, *q=NULL;
  if(!EstaVazia(l)){
    for(p=*l;p!=NULL; p=p->prox){
      q=p;
    }
  }
  else{
    printf("A lista esta vazia.\n");
  }
  if(p==NULL){
    return NULL;
  }
  if(q==NULL){
    return *l;
  }
  q->prox=NULL;
  return p;
}

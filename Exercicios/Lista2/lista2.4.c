#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
  int info;
  struct nolista *prox;
}Nolista;

typedef struct cabcauList{

  Nolista *cab, *cau;

}CabCauList;

CabCauList CriarLista(){
  CabCauList l;
  l.cab = (Nolista*)malloc(sizeof(Nolista));
  l.cau = (Nolista*)malloc(sizeof(Nolista));
  l.cau->prox = NULL;
  l.cab->prox = l.cau;
  return l;
}

int EstaVazia(CabCauList* l){
  return(l->cab->prox==l->cau);
}

void Insereinicio(CabCauList* l, int v){
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

  void ImprimeLista(CabCauList* l){
      Nolista* p;
      if(!EstaVazia(l)){
      for(p = l->cab->prox;p!=l->cau;p=p->prox){
          printf("%d\n", p->info);
      }
      }
      else{
          printf("Lista vazia\n");
      }
  }

CabCauList* UltimoPont(CabCauList* l){
  if(!EstaVazia(l)){
    return l->cau;
  }
  else{
    printf("A lista esta vazia\n");
  }
}

int Maiores(CabCauList* l, int n){
  Nolista* p;
  int i = 0;
  for(p=l->cab->prox;p!=l->cau;p=p->prox){
    if(p->info > n){
      i++;
    }
  }
    return i;
}

CabCauList* ConcatenaListas(CabCauList* l1, CabCauList* l2){
  // Verifica se alguma das listas é vazia
    if (EstaVazia(l1)) {
        return l2;
    } else if (EstaVazia(l2)) {
        return l1;
    }

    // Percorre até o último nó da primeira lista
    Nolista* p = l1->cab->prox;
    while (p->prox != l1->cau) {
        p = p->prox;
    }

    // Ajusta o ponteiro do último nó da primeira lista
    p->prox = l2->cab->prox;
    l1->cau = l2->cau;

    // Libera o nó cabeça da segunda lista (não é mais necessário)
    free(l2->cab);

    // Libera a estrutura da segunda lista
    free(l2);

    return l1;
}


CabCauList* Separa(CabCauList* l, int n) {
    if (!l || !l->cab) return NULL; // Verifica se a lista está vazia

    Nolista *atual = l->cab;
    Nolista *anterior = NULL;

    // Procurar o nó com o valor n
    while (atual && atual->info != n) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se não encontrou o valor n ou n é o último elemento
    if (!atual || !atual->prox) return NULL;

    // Cria a nova lista para a segunda parte
    CabCauList *novaLista = (CabCauList*)malloc(sizeof(CabCauList));
    if (!novaLista) return NULL;

    novaLista->cab = atual->prox;
    novaLista->cau = l->cau;

    // Ajustar a lista original
    if (anterior) {
        anterior->prox = NULL;
    } else {
        l->cab = NULL; // Se o primeiro nó é o que estamos separando, ajuste o cabeçalho da lista original
    }

    return novaLista;
}



void imprimeOrdem(CabCauList* l) {
    if (l == NULL || l->cab == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    // Conta o número de elementos na lista
    Nolista *atual = l->cab;
    int count = 0;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }

    // Cria um array para armazenar os elementos
    int *valores = (int *)malloc(count * sizeof(int));
    if (valores == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    // Armazena os valores no array
    atual = l->cab;
    for (int i = 0; i < count; i++) {
        valores[i] = atual->info;
        atual = atual->prox;
    }

    // Imprime os valores em ordem inversa
    for (int i = count - 1; i > 0; i--) {
        printf("%d\n", valores[i]);
    }
    printf("\n");

    // Libera a memória alocada para o array
    free(valores);
}

int main(){
  CabCauList lista = CriarLista();
  CabCauList lc;

  Insereinicio(&lista, 1);
  Insereinicio(&lista, 2);
  Insereinicio(&lista, 3);
  Insereinicio(&lista, 4);
  //ImprimeLista(&lista);
  //printf("---------\n");
  //UltimoPont(&lista);
  //printf("---------\n");
  //int o = Maiores(&lista, 10);
  //("%d\n", o);
  //printf("---------\n");
  CabCauList lista2 =CriarLista();
  //Insereinicio(&lista2, 4);
  //Insereinicio(&lista2, 5);
  //Insereinicio(&lista2, 6);
  //ImprimeLista(&lista2);
  //printf("---------\n");
  //ConcatenaListas(&lista, &lista2);
  //ImprimeLista(&lista);
  //printf("---------\n");
  
  lista2 = Separa(&lista, 2);
  ImprimeLista(&lista);
  printf("---------\n");
  ImprimeLista(&lc);
  ("---------\n");
  imprimeOrdem(&lista);



  return 0;
}
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

Descritor CriarLista(){
  Descritor l;
  l.prim = l.ult = NULL;
  l.n = 0;
  return l;
}

int EstaVazia(Descritor* l){
  return(l->n == 0);
}

void Insereprim(Descritor* l, int v){
  Nolista* novo = (Nolista*)malloc(sizeof(Nolista));
  if(novo!=NULL){
    novo->info=v;
    novo->prox= l->prim;
    l->prim=novo;
    if(l->n==0){
      l->ult=novo;
    }
    l->n++;
  }
  else{
    printf("Não foi possivel alocar memoria\n");
  }
}

void imprimetudo(Descritor* l){
    Nolista* p;
    if(!(EstaVazia(l))){
    for(p=l->prim;p!=NULL;p=p->prox)
        printf("%d\n", p->info);
    }
    else{
    printf("A lista esta vazia!\n");
    }
}

Descritor* ultimo(Descritor* l){
  if(!EstaVazia(l)){
    return l->ult;
  }
  else{
    printf("A lista esa vazia\n");
  }
}

int maiores(Descritor* l, int n){
  Nolista* p;
  int i = 0;
  for(p=l->prim;p!=NULL;p=p->prox){
    if(p->info>n){
      i++;
    }
  }
    return i;
}

Descritor* concatena(Descritor* l1, Descritor *l2){
  if(!EstaVazia(l1)){
    if(!EstaVazia(l2)){
      l1->ult->prox=l2->prim;
      l1->ult=l2->ult;
      l2->prim=NULL;
    }
    else{
    printf("A Segunda lista esta vazia\n");
    }
  }
  else{
    printf("A primeira lsita esta vazia\n");
  }
  return l1;
}

Descritor* separa(Descritor* l, int n) {
    Nolista* anterior = NULL;
    Descritor* nova = (Descritor*)malloc(sizeof(Descritor));
    *nova = CriarLista();

    for (Nolista* p = l->prim; p != NULL; anterior = p, p = p->prox) {
        if (p->info == n) {
            if (p->prox != NULL) {  // Verifica se há elementos após `n`
                nova->prim = p->prox;  // A nova lista começa após `n`
                nova->ult = l->ult;  // O último elemento da nova lista é o mesmo da original
                nova->n = l->n - (anterior == NULL ? 1 : l->n - 1);  // Atualiza o número de elementos na nova lista
                l->ult = p;  // Atualiza o último elemento da lista original
                p->prox = NULL;  // Quebra a lista original
                l->n = l->n - nova->n;  // Atualiza o número de elementos na lista original
            }
            break;
        }
    }

    return nova;
}

void imprimeOrdem(Descritor* l) {
    if (l->prim != NULL) {
        Nolista* p = l->ult;

        // Percorre a lista de trás para frente
        for (int i = 0; i < l->n; i++) {
            printf("%d\n", p->info);

            // Encontra o elemento anterior
            Nolista* temp = l->prim;
            while (temp->prox != p && temp->prox != NULL) {
                temp = temp->prox;
            }
            p = temp;
        }
    } else {
        printf("A lista está vazia!\n");
    }
}


int main(){

  Descritor lista;
  lista = CriarLista();
  Insereprim(&lista, 1);
  Insereprim(&lista, 2);
  Insereprim(&lista, 3);
  imprimetudo(&lista);
  printf("------------\n");
  ultimo(&lista);
  int p = maiores(&lista, 2);
  printf("%d\n", p);
   printf("------------\n");

  Descritor lista2;
  Descritor* lista_concatenada, *listasep;
  lista2 = CriarLista();
  Insereprim(&lista2, 4);
  Insereprim(&lista2, 5);
  Insereprim(&lista2, 6);
  imprimetudo(&lista2);
  //lista_concatenada = concatena(&lista, &lista2);
  //printf("------------\n");
  //imprimetudo(lista_concatenada);
  printf("------------\n");
  printf("Lista separada:\n");
  listasep = separa(&lista2, 5);
  imprimetudo(listasep);
  printf("------------\n");
  printf("lista original:\n");
  imprimetudo(&lista2);
  printf("------------\n");
  imprimeOrdem(&lista2);
  return 0;
}
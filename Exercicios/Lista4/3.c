#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int info;
    struct arvore *esq, *dir;
}Arvore;


Arvore* CriarArvoreVazia(){
    return NULL;
}

Arvore* CriarArvore(int c, Arvore* sae, Arvore* sad){
    Arvore* a = (Arvore*)malloc(sizeof(Arvore));
    if(a!=NULL){
        a->info = c;
        a->esq = sae;
        a->dir = sad;
        return a;
    }else{
        printf("Espaco nao alocado.\n");
    }
}

int Estavazia(Arvore* arv){
    return(arv == NULL);
}

void imprimeArvore(Arvore* arv){
    printf("<");
    if(!Estavazia(arv)){
        printf("%c", arv->info);
        imprimeArvore(arv->esq);
        imprimeArvore(arv->dir); //e so mudar a ordem desses 3 para mudar a ordem de impressao
        }
    printf(">");
}

Arvore* liberar(Arvore* arv){
    if(!Estavazia(arv)){
        liberar(arv->esq);
        liberar(arv->dir);
        free(arv);
    }
    return NULL;
}

int pertenceArv(Arvore* arv, char c){
    if(!Estavazia(arv)){
        if(arv->info == c){
            return 1;
        }else{
            return(pertenceArv(arv->esq, c) || pertenceArv(arv->dir, c));
        }
    }else{
        return 0;
    }
}
//Começa aqui
Arvore* busca(Arvore* a, int v){
    if(Estavazia(a)){
        return NULL;
    }else{
        if(a->info == v){
            return a;
        }else if( v < a->info){
            return(busca(a->esq, v));
        }else{
            return(busca(a->dir, v));
        }
    }
}

Arvore* insere(Arvore* a, int v){
    if(Estavazia(a)){
        a = (Arvore*)malloc(sizeof(Arvore));
        if(a!=NULL){
            a->info = v;
            a->esq = a->dir = NULL;
            return a;
        } else{
            printf("Espaco nao alocado.\n");
        }
    }else{
        if(v < a->info){
            a->esq = insere(a->esq, v);
        }else{
            a->dir = insere(a->dir, v);
        }
    }
}

int impares(Arvore* a){
    if(Estavazia(a)){
        return 0;
    }else if(a->info % 2 != 0){
        return 1 + impares(a->esq) + impares(a->dir);
    }else{
        return impares(a->esq) + impares(a->dir);
    }
}

int contNos(Arvore* arv){
    if(Estavazia(arv)){
        return 0;
    }else{  
        return 1 + contNos(arv->esq) + contNos(arv->dir);
    }
}
Arvore* menor(Arvore* a){
    if(Estavazia(a)){
        return NULL;
    }else if(Estavazia(a->esq)){
        return a;
    }else{
        return menor(a->esq);
    }
}

Arvore* maior(Arvore* a){
    if(Estavazia(a)){
        return NULL;
    }else if(Estavazia(a->dir)){
        return a;
    }else{
        return menor(a->dir);
    }
}

int qntdeChar(Arvore* arv, char c){
  if(Estavazia(arv)){
    return 0;
  }else{
    if(arv->info == c){
      return 1 + qntdeChar(arv->dir, c);
    }else{
      if(c < arv->info)
      return qntdeChar(arv->esq, c);
      else
      return qntdeChar(arv->dir, c);
    }
  }
}

int maiorex(Arvore* arv){
    if(Estavazia(arv)){
        return -1;
    }
    
    int maiordir = maiorex(arv->dir);
    int maiorvalor = arv->info;

    if(maiordir >= maiorvalor)
        maiorvalor = maiordir;

    return maiorvalor;
}

int main(){
    Arvore* a = CriarArvoreVazia(); //depois coloca os elemetos dentro
    a = insere(a, 1);
    a = insere(a, 2);
    a = insere(a, 5);
    a = insere(a, 9);
    a = insere(a, 0);
    a = insere(a, 6);

    printf("\n");
    int i = maiorex(a);
    printf("%d", i);
    printf("\n"); 
    return 0;
}

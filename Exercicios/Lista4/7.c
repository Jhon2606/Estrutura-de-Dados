#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    char info;
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
        printf("%d", arv->info);
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



int ocorrencias_x(Arvore* arv, int x) {
    if (Estavazia(arv)) {
        return 0;
    } else if (arv->info == x) {
        return 1 + ocorrencias_x(arv->esq, x) + ocorrencias_x(arv->dir, x);
    } else if (x < arv->info) {
        return ocorrencias_x(arv->esq, x);
    } else {
  
        return ocorrencias_x(arv->dir, x);
    }
}

void imprimecontrario(Arvore* arv){
  if(!Estavazia(arv)){

    imprimecontrario(arv->dir);

    if(arv->esq == NULL && arv->dir == NULL){
    printf("%d ", arv->info);
    
    }

    imprimecontrario(arv->esq);

  }
}

void imprimeArvorecrec(Arvore* arv){
    printf("<");
    if(!Estavazia(arv)){
        imprimeArvorecrec(arv->esq);
        printf("%d", arv->info);
        imprimeArvorecrec(arv->dir); //e so mudar a ordem desses 3 para mudar a ordem de impressao
        }
    printf(">");
}

int main(){
    Arvore* a = CriarArvoreVazia();
    a = insere(a, 10);
    a = insere(a, 6);
    a = insere(a, 6);
    a = insere(a, 3);
    a = insere(a, 8);
    a = insere(a, 4);
    printf("\n");
    imprimeArvorecrec(a);
    printf("\n");
    return 0;
}

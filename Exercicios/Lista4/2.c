#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int info;
    struct arvore *esq, *mei, *dir;
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

int pertenceArv(Arvore* arv, int c){
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

int contNos(Arvore* arv){
    if(Estavazia(arv)){
        return 0;
    }else{
        return 1 + contNos(arv->esq) + contNos(arv->dir);
    }
}

int altura(Arvore* arv){
    if(Estavazia(arv)){
        return -1;
    }else{
        if(Estavazia(arv->esq) && Estavazia(arv->dir)){
            return 0;
        }else{
            int he = altura(arv->esq);
            int hd = altura(arv->dir);
            if(he > hd){
                return he + 1;
            }else{
                return hd + 1;
            }
        }
    }
}

int qntFolhas(Arvore* arv){
    if(Estavazia(arv)){
        return 0;
    }else{
        if(arv->dir == NULL && arv->esq == NULL){
            return 1;
        }else{
            return qntFolhas(arv->esq) + qntFolhas(arv->dir);
        }
    }
}

int qntdeChar(Arvore* arv, int c){
  if(Estavazia(arv)){
    return 0;
  }else{
    if(arv->info == c){
      return 1 + qntdeChar(arv->esq, c) + qntdeChar(arv->dir, c);
    }else{
      return qntdeChar(arv->esq, c) + qntdeChar(arv->dir, c);
    }
  }
}

int iguais(Arvore* a, Arvore *b){
    if(Estavazia(a) && Estavazia(b)){
        return 1;
    }else if(Estavazia(a) || Estavazia(b)){
        return 0;
    }else if(a->info == b->info){
        return iguais(a->esq, b->esq) && iguais(a->dir, b->dir);
    }else{
        return 0;
    }
}

Arvore* copia(Arvore* arv){
    if(Estavazia(arv)){
        return CriarArvoreVazia();
    }else{
        Arvore* arv2 = (Arvore*)malloc(sizeof(Arvore));
        arv2->info = arv->info;
        arv2->dir = copia(arv->dir);
        arv2->esq = copia(arv->esq);
        return arv2;
    }
}

int maior(Arvore* arv){
    if(Estavazia(arv)){
        return -1;
    }

    int maioresq = maior(arv->esq);
    int maiordir = maior(arv->dir);
    int maiorvalor = arv->info;

    if(maioresq >= maiorvalor)
        maiorvalor = maioresq;
    if(maiordir >= maiorvalor)
        maiorvalor = maiordir;

    return maiorvalor;
}
//Questão 6
int contcel(Arvore* arv){
    if(Estavazia(arv)){
        return 0;
    }else{
        return 1 + contcel(arv->esq) + contcel(arv->dir) + contcel(arv->mei);
    }
}

int main(){
    Arvore* f = CriarArvore(1, CriarArvoreVazia(), CriarArvoreVazia());
    Arvore* e = CriarArvore(2, CriarArvoreVazia(), CriarArvoreVazia());
    Arvore* d = CriarArvore(3, CriarArvoreVazia(), CriarArvoreVazia());
    Arvore* c = CriarArvore(4, e, f);
    Arvore* b = CriarArvore(5, CriarArvoreVazia(), d);
    Arvore* a = CriarArvore(6, b, c);
    printf("\n");
    int i = maior(a);
    printf("%d", i);
    printf("\n");
    //imprimeArvore(a);
    return 0;
}
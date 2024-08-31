#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    char info;
    struct arvore *esq, *dir;
}Arvore;

Arvore* CriarArvoreVazia(){
    return NULL;
}

Arvore* CriarArvore(char c, Arvore* sae, Arvore* sad){
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

int main(){
    Arvore* f = CriarArvore('f', CriarArvoreVazia(), CriarArvoreVazia());
    Arvore* e = CriarArvore('e', CriarArvoreVazia(), CriarArvoreVazia());
    Arvore* d = CriarArvore('d', CriarArvoreVazia(), CriarArvoreVazia());
    Arvore* c = CriarArvore('c', e, f);
    Arvore* b = CriarArvore('b', CriarArvoreVazia(), d);
    Arvore* a = CriarArvore('a', b, c);
    printf("\n");
    imprimeArvore(a);
    printf("\n");

    return 0;
}
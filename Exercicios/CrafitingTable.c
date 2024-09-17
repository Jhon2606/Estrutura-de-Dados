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
        return NULL;
    }
}

int EstaVazia(Arvore* arv){
    return(arv == NULL);
}

void ImprimeArvore(Arvore* arv){
    printf("<");
    if(!EstaVazia(arv)){
        printf("%c", arv->info);
        ImprimeArvore(arv->esq);
        ImprimeArvore(arv->dir);
    }
    printf(">");
}

Arvore* LiberarArvore(Arvore* arv){
    if(!EstaVazia(arv)){
        LiberarArvore(arv->esq);
        LiberarArvore(arv->dir);
        free(arv);
    }
    return NULL;
}

int PertenceArv(Arvore* arv, char c){
    if(!EstaVazia(arv)){
        if(arv->info == c){
            return 1;
        }else{
            return(PertenceArv(arv->esq, c) || PertenceArv(arv->dir, c));
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
    Arvore* i = LiberarArvore(a);
    if(i == NULL){
        printf("Vazio\n");
    }
    printf("\n");

    return 0;
}
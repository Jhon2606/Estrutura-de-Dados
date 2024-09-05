#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    char info;
    struct arvore *esq, *dir;
}Arvore;


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

Arvore* remove(Arvore* a, int v){
    if(Estavazia(a)){
        return NULL;
    }else{
        if(v < a->info){
            a->esq = remove(a->esq, v);
        }else if (v > a->info){
            a->dir = remove(a->dir, v);
        }else{
            if(a->esq == NULL && a->dir == NULL){
                free(a);
                a = NULL;
            }else if(a->esq == NULL){
                Arvore* t = a->dir;
                free(a);
                a = t;
            }else if(a->dir == NULL){
                Arvore* t = a->esq;
                free(a);
                a = t;
            }else{
                Arvore* t = a->esq;
                while(t->dir!=NULL){
                    t =t->dir;
                }
            a->info = t->info;
            t->info = v;
            a->esq = remove(a->esq, v);
            }
        }
    }
    return a;
}

int main(){
    Arvore* a = CriarArvore(); //depois coloca os elemetos dentro
    a = insre(a, 2);
    a = insere(a, 4);
    a = remove(a, 2);
    printf("\n");
    imprimeArvore(a);
    printf("\n"); 
    if(busca(a, 2) != NULL){
        printf("No encontrado\n");
    }else{
        printf("No nao encontrado.\n");
    }
    return 0;
}

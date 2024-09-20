#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int info;
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

int Cont_Nao_folhas(Arvore* arv){
    if(Estavazia(arv)){
        return 0;
    }else if(arv->esq == NULL && arv->dir == NULL){
    return 0;
  }else{
    return 1 + Cont_Nao_folhas(arv->esq) + Cont_Nao_folhas(arv->dir);
  }
}

int Menor_val(Arvore* arv) {
    if (Estavazia(arv)) {
        return arv->info;  // Aqui não faz sentido acessar arv->info, pois a árvore está vazia
    }

    // Começamos com o valor do nó atual
    int menor = arv->info;

    // Verificamos o menor valor na subárvore esquerda, se ela existir
    if (!Estavazia(arv->esq)) {
        int menor_esq = Menor_val(arv->esq);
        if (menor_esq < menor) {
            menor = menor_esq;
        }
    }

    // Verificamos o menor valor na subárvore direita, se ela existir
    if (!Estavazia(arv->dir)) {
        int menor_dir = Menor_val(arv->dir);
        if (menor_dir < menor) {
            menor = menor_dir;
        }
    }

    return menor;
}

Arvore* espelhar(Arvore* arv) {
    if (Estavazia(arv)) {
        return NULL;
    }
    Arvore* arv2 = CriarArvore(arv->info, espelhar(arv->dir), espelhar(arv->esq));
    return arv2;
}


int main(){
    Arvore* f = CriarArvore(10, CriarArvoreVazia(), CriarArvoreVazia());
    Arvore* e = CriarArvore(6, CriarArvoreVazia(), CriarArvoreVazia());
    Arvore* d = CriarArvore(7, CriarArvoreVazia(), CriarArvoreVazia());   
    Arvore* c = CriarArvore(9, e, f);
    Arvore* b = CriarArvore(3, CriarArvoreVazia(), d);
    Arvore* a = CriarArvore(5, b, c);
    printf("\n");
    imprimeArvore(a);
    printf("\n");
    Arvore* i = espelhar(a);
    imprimeArvore(i);
    return 0;
}
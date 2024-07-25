#include "lista.h"

int main(){

    Lista* Lista = criarLista();
    estaVazia(Lista); //Esta passando Lista para l
    estaCheia(Lista);
    inserirElemento(Lista, 2);
    inserirElemento(Lista, 3);
    imprimeLista(Lista);
    removeElemento(Lista, 2);
    imprimeLista(Lista);
    return 0;
}

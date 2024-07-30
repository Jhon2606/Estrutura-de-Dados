#define MAX 10

typedef struct lista{

    int itens[MAX], n;

}Lista;

Lista* criarLista();
int estaVazia(Lista* l);
int estaCheia(Lista* l);
void inserirElemento(Lista* l, int v);
void imprimeLista(Lista* l);
void removeElemento(Lista* l, int i);
#include <stdio.h>

int main(){
    int mat;
    char nome[30];
    FILE* arq = fopen("arquivo.txt","r");
    if(arq!=NULL){
        while(fscanf(arq, "%d\t%s", &mat, nome) == 2)
        printf("%d - %s\n", mat, nome);

        fclose(arq);
    }else{
        printf("Nao foi posivel abri o arquivo.\n");
    }
    return 0;
}

/*int main(){
    int mat;
    char nome[30];
    FILE* arq = fopen("saida.txt","w");
    if(arq!=NULL){
        printf("Digite seu nome:");
        scanf("%s", nome);
        fprintf(arq, "%s\n",nome);

        fclose(arq);
    }else{
        printf("Nao foi posivel abri o arquivo.\n");
    }
    return 0;
}*/

/*int main(){
    int mat;
    char nome[30];
    FILE* arq = fopen("arquivo.txt","r");
    if(arq!=NULL){
        printf("Tem arquivo.\n");

        fclose(arq);
    }else{
        printf("Nao foi posivel abri o arquivo.\n");
    }
    return 0;
}*/
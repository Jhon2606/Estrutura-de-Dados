#include <stdio.h>
#include <stdlib.h>

#define tam 5

void inverte(int n, int *v);

int main() {
    int i, v1[tam];

    printf("Digite os valores do vetor:\n");
    for(i = 0; i < tam; i++){
        scanf("%d", &v1[i]);
    }

    inverte(tam, v1);

    printf("Vetor invertido:\n");
    for(i = 0; i < tam; i++){
        printf("%d ", v1[i]);
    }
    printf("\n");

    return 0;
}

void inverte(int n, int *v) {
    int i, temp;

    for(i = 0; i < n / 2; i++){
        temp = v[i];
        v[i] = v[n - i - 1];
        v[n - i - 1] = temp;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> // Necessário para strlen

char* shift_string(char *str);

int main() {
    char p[10], *v;

    printf("Digite uma palavra:\n");
    scanf("%9s", p); // Limita a leitura para evitar overflow

    v = shift_string(p); // Correto: atribui o ponteiro retornado

    if (v != NULL) {
        printf("String deslocada: %s\n", v);
        printf("String anterior: %s\n", p);

        free(v); // Libera a memória alocada
    } else {
        printf("Erro na alocação de memória.\n");
    }

    return 0;
}

char* shift_string(char *str) {
    size_t len = strlen(str); // Obtém o comprimento da string original
    char *p = (char *)malloc((len + 1) * sizeof(char)); // Aloca memória para a nova string

    if (p == NULL) {
        return NULL; // Retorna NULL se a alocação falhar
    }

    for (size_t i = 0; i < len; ++i) {
        if (isalpha(str[i])) {
            if (str[i] == 'z') {
                p[i] = 'a';
            } else if (str[i] == 'Z') {
                p[i] = 'A';
            } else {
                p[i] = str[i] + 1;
            }
        } else {
            p[i] = str[i]; // Copia caracteres não alfabéticos sem alteração
        }
    }
    p[len] = '\0'; // Adiciona o terminador nulo

    return p; // Retorna o ponteiro para a nova string
}
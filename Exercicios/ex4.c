#include <stdio.h>
#include <stdlib.h>

typedef struct realtype {
  int left;
  int right;
} Real;

void leReal(Real *r);
void imprimeReal(Real *r);
Real soma(Real *r1, Real *r2);

int main() {
  Real n1, n2, resultado;

  printf("Digite o primeiro número:\n");
  leReal(&n1);

  printf("Digite o segundo número:\n");
  leReal(&n2);

  resultado = soma(&n1, &n2);

  printf("A soma dos números é: ");
  imprimeReal(&resultado);

  return 0;
}

void leReal(Real *r) {
  printf("Digite a parte inteira e a parte fracionária do número:\n");
  scanf("%d %d", &r->left, &r->right);
}

void imprimeReal(Real *r) {
  printf("%d.%02d\n", r->left, r->right);
}

Real soma(Real *r1, Real *r2) {
  Real resultado;
  int carry = 0;

  resultado.right = r1->right + r2->right;

  if (resultado.right >= 100) {
    resultado.right -= 100;
    carry = 1;
  }

  resultado.left = r1->left + r2->left + carry;

  return resultado;
}
#include <stdio.h>
#include <string.h>

int Soma(char num[]) {
  int tam = strlen(num);
  int resultado = 0;
  for (int i = 0; i < tam; i++){
    resultado = resultado + (num[i] - '0'); // Converte char para int
  }
  return resultado;
}

int main() {
  char num[100];
  printf("Digite um numero natural: ");
  scanf("%s", num);
  printf("A soma dos digitos e: %d\n", Soma(num));
}

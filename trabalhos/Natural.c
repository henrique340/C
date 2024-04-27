#include <stdio.h>
#include <string.h>

int digitos(char num[]) {
  return strlen(num);
}

int main() {
  char num[100];
  printf("Digite um numero natural: ");
  scanf("%s", num);
  printf("Numero de digitos: %d\n", digitos(num));
}

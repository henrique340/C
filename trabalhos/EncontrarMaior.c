#include <stdio.h>

// Função recursiva para encontrar o maior elemento em um vetor usando divisão e conquista
int encontrarMaior(int v[], int inicio, int fim) {
  // Caso base: se o vetor tem apenas um elemento, retornar esse elemento
  if (inicio == fim) {
    return v[inicio];
  } else {
    // Calcular o índice do meio do vetor
    int meio = (inicio + fim) / 2;

    // Encontrar o maior elemento na metade esquerda do vetor
    int maior_esquerda = encontrarMaior(v, inicio, meio);

    // Encontrar o maior elemento na metade direita do vetor
    int maior_direita = encontrarMaior(v, meio + 1, fim);

    // Retornar o maior elemento entre a metade esquerda e a metade direita
    if (maior_direita>maior_esquerda){
      return maior_direita;
    } else {
      return maior_esquerda;
    }
  }
}

int main() {
  int vetor[] = {10, 5, 7, 20, 15, 25, 30};
  int tamanho = sizeof(vetor) / sizeof(vetor[0]);

  // Encontrar o maior elemento no vetor
  int maior = encontrarMaior(vetor, 0, tamanho - 1);

  printf("O maior elemento no vetor: %d\n", maior);

  return 0;
}

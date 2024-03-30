#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos em um vetor
void trocar(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Função para particionar o vetor
int separa(int vetor[], int p, int r) {
  // Escolher um índice aleatório entre p e r
  int indiceAleatorio = p + rand() % (r - p + 1);
  int pivo = vetor[indiceAleatorio];

  // Colocar o pivô no lugar certo
  trocar(&vetor[indiceAleatorio], &vetor[r]);

  int i = p - 1;

  for (int j = p; j < r; j++) {
    if (vetor[j] <= pivo) {
      i++;
      trocar(&vetor[i], &vetor[j]);
    }
  }

  trocar(&vetor[i + 1], &vetor[r]);
  return i + 1;
}

// Função de ordenação QuickSort
void quickSort(int vetor[], int p, int r) {
  if (p < r) {
    int q = separa(vetor, p, r);
    quickSort(vetor, p, q - 1);
    quickSort(vetor, q + 1, r);
  }
}

// Função para imprimir um vetor
void imprimirVetor(int vetor[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main() {
  int vetor[] = {10, 7, 8, 9, 1, 5};
  int tamanho = sizeof(vetor) / sizeof(vetor[0]);

  // Inicializar o gerador de números aleatórios
  srand(time(NULL));

  printf("Vetor antes da ordenacao:\n");
  imprimirVetor(vetor, tamanho);

  quickSort(vetor, 0, tamanho - 1);

  printf("Vetor depois da ordenacao:\n");
  imprimirVetor(vetor, tamanho);

  return 0;
}

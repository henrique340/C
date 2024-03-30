#include <stdio.h>

// Função para trocar dois elementos em um vetor
void trocar(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Função para encontrar a mediana de três números
int medianaDeTres(int vetor[], int p, int q, int r) {
  int meio = (p + q + r) / 3;
    
  // Ordenar os três elementos
  if (vetor[p] > vetor[meio])
    trocar(&vetor[p], &vetor[meio]);
  if (vetor[p] > vetor[r])
    trocar(&vetor[p], &vetor[r]);
  if (vetor[meio] > vetor[r])
    trocar(&vetor[meio], &vetor[r]);

  return meio;
}

// Função para particionar o vetor
int separa(int vetor[], int p, int r) {
  // Escolher o pivô usando a mediana de três
  int indicePivo = medianaDeTres(vetor, p , (p + r) / 2 , r);
  int pivo = vetor[indicePivo];

  // Colocar o pivô no lugar certo
  trocar(&vetor[indicePivo], &vetor[r]);

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

  printf("Vetor antes da ordenacao:\n");
  imprimirVetor(vetor, tamanho);

  quickSort(vetor, 0, tamanho - 1);

  printf("Vetor depois da ordenacao:\n");
  imprimirVetor(vetor, tamanho);

  return 0;
}

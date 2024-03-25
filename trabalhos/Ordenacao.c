#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar um vetor aleatoriamente
void vetorAleatorio(int vetor[], int tam){
  srand(time(NULL));
  for (int i = 0; i < tam; i++)
  {
    vetor[i] = rand() % 100; // Valores aleatórios de 0 a 100
  }
}

// Função que printa o vetor
void imprimirVetor(int vetor[], int tam){
  for (int i = 0; i < tam; i++)
  {
    printf("%d ",vetor[i]);
  }
  printf("\n");
}

// Algoritimo Bubble Sort
void bubbleSort(int vetor[], int tam){
  for (int i = 0; i < tam - 1; i++)
  {
    for (int j = 0; j < tam - 1; j++)
    {
      if (vetor[j] > vetor[j+1]){
        int temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
    }
  }
}

// Algoritimo Insertion Sort
void insertionSort(int vetor[], int tam){
  int i, chave, j;
  for (i = 1; i < tam; i++){
    chave = vetor[i];
    j = i-1;
    while (j >= 0 && vetor[j] > chave){
      vetor[j+1] = vetor[j];
      j = j-1;
    }
    vetor[j+1] = chave;
  }
}

// Algoritimo Selection Sort
void selectionSort(int vetor[], int tam){
  int i, j, min, temp;
  for (i = 0; i < tam - 1; i++)
  {
    min = i;
    for (j = i + 1; j < tam; j++)
    {
      if (vetor[j] < vetor[min])
      {
        min = j;
      }
    }
    temp = vetor[i];
    vetor[i] = vetor[min];
    vetor[min] = temp;
  }
}

// Algoritimo Shell Sort
void shellSort(int vetor[], int tam){
  int i, meio, temp, j;
  for (meio = tam/2; meio > 0; meio /= 2){
    for (i = meio; i < tam; i += 1){
      temp = vetor[i];
      for (j = i; j >= meio && vetor[j-meio] > temp; j -= meio){
        vetor[j] = vetor[j-meio];
      }
      vetor[j] = temp;
    }
  }
}


int main(){
  char letra;
  
  // Menu de opções de ordenações
  printf("a - bubble sort\nb - insertion sort\nc - selection sort\nd - shell sort\n");
  printf("Digite a opcao: ");
  scanf(" %c", &letra);

  int vetor[10000];   // Declaração do vetor

  // Bubble Sort
  if (letra == 'a') {
    int opcao;
    printf("1 - [1000]\n2 - [5000]\n3 - [10000]\n");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    
    case 1:
      vetorAleatorio(vetor, 1000);
      printf("\nO vetor gerado aleatoriamente fica assim: ");
      imprimirVetor(vetor, 1000);
      printf("\nO vetor ordenado por Bubble Sort fica assim: ");
      bubbleSort(vetor, 1000);
      imprimirVetor(vetor, 1000);
      break;
    
    case 2:
      vetorAleatorio(vetor, 5000);
      printf("\nO vetor gerado aleatoriamente fica assim: ");
      imprimirVetor(vetor, 5000);
      printf("\nO vetor ordenado por Bubble Sort fica assim: ");
      bubbleSort(vetor, 5000);
      imprimirVetor(vetor, 5000);
      break;
    
    case 3:
      vetorAleatorio(vetor, 10000);
      printf("\nO vetor gerado aleatoriamente fica assim: ");
      imprimirVetor(vetor, 10000);
      printf("\nO vetor ordenado por Bubble Sort fica assim: ");
      bubbleSort(vetor, 10000);
      imprimirVetor(vetor, 10000);
      break;
    
    default:
      printf("\nOpcao nao reconhecida\n");
      return 1;
    }

  // Insertion Sort
  } else if (letra == 'b') {
    int opcao;
    printf("1 - [1000]\n2 - [5000]\n3 - [10000]\n");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    
    case 1:
      vetorAleatorio(vetor, 1000);
      printf("\nO vetor gerado aleatoriamente fica assim: ");
      imprimirVetor(vetor, 1000);
      printf("\nO vetor ordenado por Insertion Sort fica assim: ");
      insertionSort(vetor, 1000);
      imprimirVetor(vetor, 1000);
      break;
    
    case 2:
      vetorAleatorio(vetor, 5000);
      printf("\nO vetor gerado aleatoriamente fica assim: ");
      imprimirVetor(vetor, 5000);
      printf("\nO vetor ordenado por Insertion Sort fica assim: ");
      insertionSort(vetor, 5000);
      imprimirVetor(vetor, 5000);
      break;
    
    case 3:
      vetorAleatorio(vetor, 10000);
      printf("\nO vetor gerado aleatoriamente fica assim: ");
      imprimirVetor(vetor, 10000);
      printf("\nO vetor ordenado por Insertion Sort fica assim: ");
      insertionSort(vetor, 10000);
      imprimirVetor(vetor, 10000);
      break;
    
    default:
      printf("\nOpcao nao reconhecida\n");
      return 1;
    }

  } else if (letra == 'c') {
    int opcao;
    printf("1 - [1000]\n2 - [5000]\n3 - [10000]\n");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {

    case 1:
      vetorAleatorio(vetor, 1000);
      printf("\nO vetor gerado aleatoriamente fica assim: ");
      imprimirVetor(vetor, 1000);
      printf("\nO vetor ordenado por Selection Sort fica assim: ");
      selectionSort(vetor, 1000);
      imprimirVetor(vetor, 1000);
      break;

    case 2:
      vetorAleatorio(vetor, 5000);
      printf("\nO vetor gerado aleatoriamente fica assim: ");
      imprimirVetor(vetor, 5000);
      printf("\nO vetor ordenado por Selection Sort fica assim: ");
      selectionSort(vetor, 5000);
      imprimirVetor(vetor, 5000);
      break;

    case 3:
      vetorAleatorio(vetor, 10000);
      printf("\nO vetor gerado aleatoriamente fica assim: ");
      imprimirVetor(vetor, 10000);
      printf("\nO vetor ordenado por Selection Sort fica assim: ");
      selectionSort(vetor, 10000);
      imprimirVetor(vetor, 10000);
      break;

    default:
      printf("Opcao nao reconhecida\n");
      return 1;
    }

  } else if (letra == 'd'){
    int opcao;
    printf("1 - [1000]\n2 - [5000]\n3 - [10000]\n");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    
    case 1:
      vetorAleatorio(vetor, 1000);
      printf("\nO vetor gerado aleatoriamente fica assim: ");
      imprimirVetor(vetor, 1000);
      printf("\nO vetor ordenado por Shell Sort fica assim: ");
      shellSort(vetor, 1000);
      imprimirVetor(vetor, 1000);
      break;
    
    case 2:
      vetorAleatorio(vetor, 5000);
      printf("\nO vetor gerado aleatoriamente fica assim: ");
      imprimirVetor(vetor, 5000);
      printf("\nO vetor ordenado por Shell Sort fica assim: ");
      shellSort(vetor, 5000);
      imprimirVetor(vetor, 5000);
      break;
    
    case 3:
      vetorAleatorio(vetor, 10000);
      printf("\nO vetor gerado aleatoriamente fica assim: ");
      imprimirVetor(vetor, 10000);
      printf("\nO vetor ordenado por Shell Sort fica assim: ");
      shellSort(vetor, 10000);
      imprimirVetor(vetor, 10000);
      break;
    
    default:
      printf("Opcao nao reconhecida\n");
      return 1;
    }

  } else {
    return 0;
  }
}
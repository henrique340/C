#include <stdio.h>

// Ordenar para achar mais fácil o maior e o menor elemento
int Ordenar(int S[], int tam){
  for (int i = 0; i < tam; i++){
    for (int j = 0; j < tam-i-1; j++){
      if (S[j] > S[j+1]){
        int temp = S[j+1];
        S[j+1] = S[j];
        S[j] = temp;
      }
    }
  }
}

// Elemento Maximo
int ElementoMaximo(int S[], int tam){
  Ordenar(S, tam);
  return S[tam-1];
}

// Elemento mínimo
int ElementoMinimo(int S[], int tam){
  Ordenar(S, tam);
  return S[0];
}

// Soma dos elementos
int SomaElementos(int S[], int tam){
  int resultado = 0;
  for (int i = 0; i < tam; i++){
    resultado += S[i];
  }
  return resultado;
}

// Soma dos elementos pares
int SomaPares(int S[], int tam){
  int Soma = 0;
  for (int i = 0; i< tam; i++){
    if (S[i] % 2 == 0){
      Soma += S[i];
    }
  }
  return Soma;
}

//  Busca linear
int BuscaLinear(int S[], int tam, int elemento){
  for (int i = 0; i < tam; i++){
    if (elemento == S[i]){
      return i;
    }
  }
}

int main(){
  int S[] = {1, 3, 5, 2, 8, 9};
  int tam = sizeof(S)/sizeof(S[0]);
  printf("O maior elemento e: %d\n", ElementoMaximo(S, tam));
  printf("O menor elemento e: %d\n", ElementoMinimo(S, tam));
  printf("A soma dos elementos e: %d\n", SomaElementos(S, tam));
  printf("A soma dos elementos pares e: %d\n", SomaPares(S, tam));
  int elemento = 5;
  printf("A posicao do elemento %d e: %d", elemento, BuscaLinear(S, tam, elemento));
}

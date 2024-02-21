#include <stdio.h>
#include <string.h>
#include <locale.h>

// Escreva uma função que decida se um vetor de caracter é ou não um palíndromo

void palindromo(char lista[], int tam){
  int i;
  char str2[100] = "";
  for (i= tam-1; i>=0; i--){
    strncat(str2, &lista[i], 1);
  }
  for (i=0; i<tam; i++){
    if (str2[i] != lista[i]){
      printf("Nao e um palindromo");
    }
  }
  printf("E um palindromo");
}

int main(){
  setlocale(LC_ALL, "Portuguese");
  char str1[100];
  printf("Digite uma palavra: ");
  scanf("%s", str1);
  int tam = strlen(str1);
  palindromo(str1, tam);

  return 0;
}
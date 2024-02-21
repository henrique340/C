#include <stdio.h>
#include <string.h>
#include <locale.h>

// Escreva uma função que recebe um vetor de caractere e um caracter , a função remove todas as ocorrências do caracter na string sem deixar buracos

void remover(char vetor[], char caracter){
  int i, j;
  j = 0;
  int tam = strlen(vetor);
  for (i=0; i<tam; i++){
    if (vetor[i] != caracter){
      vetor[j++] = vetor[i];
    }
  }
  printf("%s", vetor);
}

int main(){
  setlocale(LC_ALL, "Portuguese");
  char string[] = "abacaxi verde";
  char caracter;
  printf("Digite o caracter para remover da string: ");
  scanf("%c", &caracter);
  remover(string, caracter);
}




// abracadabra
// vetor[0] = 'a'
// vetor[1] = 'b'
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// Escreva uma função que receba um vetor e imprima uma tabela com cada ocorrência de cada caractere

void tabela(char lista[]){
  int ocorrencias[100] = {0};
  int tam = strlen(lista);
  int i;
  for (i=0; i<tam; i++){
    ocorrencias[(unsigned char)lista[i]]++;
  }

  for(i=0; i<tam;i++){
    printf("%c \t\t %d\n", (char)i, ocorrencias[i]);
  }
}

int main(){
  setlocale(LC_ALL, "Portuguese");
  char vetor[] = "aabcccddeeee";
  tabela(vetor);
}
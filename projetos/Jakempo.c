#include <stdio.h>
#include <locale.h>
#include <time.h>

char random(){
  char letras[] = "PRT";
  int tamanho = sizeof(letras);
  int indice = rand() % tamanho;
  return letras[indice];
}

int main(){
  printf("------------------\n");
  printf("Jokempo\n");
  printf("------------------\n\n");
  
  char opc;
  printf("Deseja jogar? [S]/[N]: ");
  scanf("%c", &opc);

  if (opc == 'S'){
    printf("Digite [R] para pedra\n");
    printf("Digite [P] para papel\n");
    printf("Digite [T] para tesoura\n");
    
    char opcao;
    printf("Opção: ");
    scanf("%c", &opcao);

    srand(time(NULL));

    char aleatorio = random();
    printf("O computador jogou %c\n", aleatorio);
    printf("Voce jogou %c\n", opcao);
  }
}
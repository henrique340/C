#include <stdio.h>
#include <locale.h>

void trocar(int disco, int destino)
{
}

int main()
{
  setlocale(LC_ALL, "Portuguese");
  char disco, pilar;

  // situação do jogo
  int situacaoP1[6] = {6, 5, 4, 3, 2, 1};
  int situacaoP2[6] = {};
  int situacaoP3[6] = {};

  // explicação do jogo
  printf("Jogo da Torre de Hanui\n\n");
  printf("O jogo consiste em conseguir empilhar uma torre de discos do maior diâmetro até o menor diâmetro\n");
  printf("Existem 3 pilares [P1] [P2] [P3]\n");
  printf("E existem 6 discos [p1] [p2] [p3] [p4] [p5] [p6], sendo p1 o de menor diâmetro e p6 o de maior diâmetro\n");
  printf("Você só pode colocar um disco de menor diâmetro em cima de um de maior\n");
  printf("Para jogar, você deve indicar dois parâmetros [disco][pilar]\n\n");

  // input do usuário
  printf("P1 contém ");
  printf("[");
  for (int i = 0; i < 6; i++)
  {
    printf("%d ", situacaoP1[i]);
  }
  printf("]");
  printf("\nP2 contém ");
  printf("[");
  for (int i = 0; i < 6; i++)
  {
    printf("%d ", situacaoP2[i]);
  }
  printf("]");
  printf("\nP3 contém ");
  printf("[");
  for (int i = 0; i < 6; i++)
  {
    printf("%d ", situacaoP3[i]);
  }
  printf("]");
  printf("\nDigite a sua jogada: ");
  scanf("%s %s", &disco, &pilar);
}
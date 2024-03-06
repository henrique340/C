#include <stdio.h>

int main(){
  int num;
  printf("Digite um numero de 4 algarismos: ");
  scanf("%d", &num);
  int unidade = num%10;
  int dezena = (num/10)%10;
  int centena = (num/100)%10;
  int milhar = (num/1000)%10;
  printf("A unidade e: %d\nA dezena e: %d\nA centena e: %d\n O milhar e: %d",unidade, dezena, centena, milhar);
}
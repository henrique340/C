#include <stdio.h>

// Função Recursiva
int recursiva(int num1, int num2){
  if (num1 >= num2 && num1 % num2 == 0){
    return num2;
  } else if (num1 < num2){
    return recursiva(num2, num1);
  } else {
    return recursiva(num2, num1 % num2);
  }
}

// Função Iterativa
int iterativa(int num1, int num2){
  if (num1 >= num2 && num1 % num2 == 0){
    return num2;
  } else {
    while (num2 != 0){
      int temp = num2;
      num2 = num1 % num2;
      num1 = temp;
    }
    return num1;
  }
}

int main(){
  int n1, n2;
  printf("Digite o primeiro numero para calcular o MDC: ");
  scanf("%d", &n1);
  printf("Digite o segundo numero para calcular o MDC: ");
  scanf("%d", &n2);
  printf("Usando a funcao recursiva: ");
  printf("%d\n", recursiva(n1,n2));
  printf("Usando a funcao iterativa: ");
  printf("%d", iterativa(n1, n2));
}

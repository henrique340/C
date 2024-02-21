#include <stdio.h>
#include <string.h>
#include <locale.h>

//escreva um programa que leia três strings e encontre a maior lexicografamente

int main(){
  setlocale(LC_ALL, "Portuguese");
  char str1[100], str2[100], str3[100];

  printf("Digite a primeira string: ");
  scanf("%s", str1);
  printf("Digite a segunda string: ");
  scanf("%s", str2);
  printf("Digite a terceira string: ");
  scanf("%s", str3);

  if (strcmp(str1, str2) > 0 && strcmp(str1, str3) > 0){
    printf("A string %s é maior ", str1);
  }
  else if (strcmp(str2, str1) > 0 && strcmp(str2, str3) > 0){
    printf("A string %s é maior", str2);
  }
  else{
    printf("A string %s é maior", str3);
  }

  return 0;
}
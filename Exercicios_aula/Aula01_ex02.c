#include <stdio.h>
#include <locale.h>
#include <string.h>

//Escreva um programa que leia três strings e as apresente em ordem lexicográfica crescente

int main(){
  char str1[100], str2[100], str3[100];
  printf("Digite a primeira string: ");
  scanf("%s", str1);
  printf("Digite a segunda string: ");
  scanf("%s", str2);
  printf("Digite a terceira string: ");
  scanf("%s", str3);

  if (strcmp(str1, str2) > 0 && strcmp(str1, str3) > 0) {
    if (strcmp(str2, str3) > 0){
      printf("A sequência crescente é %s %s %s", str3 ,str2, str1);
    }
    else if (strcmp(str3, str2) > 0){
      printf("A sequência crescente é %s %s %s", str2, str3, str1);
    }
  }

  else if (strcmp(str2, str1) > 0 && strcmp(str2, str3) > 0){
    if (strcmp(str1,str3) > 0){
      printf("A sequência crescente é %s %s %s", str3, str1, str2);
    }
    else if(strcmp(str3, str1) > 0){
      printf("A sequência crescente é %s %s %s", str1, str3, str2);
    }
  }

  else if(strcmp(str3, str1)>0 && strcmp(str3, str2)>0){
    if (strcmp(str1, str2) > 0){
      printf("A sequência crescente é %s %s %s", str2, str1, str3);
    }
    else if(strcmp(str2, str1) > 0){
      printf("A sequência crescente é %s %s %s", str1, str2, str3);
    }
  }
}
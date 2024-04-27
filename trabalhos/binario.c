#include <stdio.h>

// Função recursiva para binário
void binario(int num, int lista[], int *tamanho) { // Ponteiro tamanho para usar depois
    if (num > 1) {
        binario(num / 2, lista, tamanho);
    }
    lista[(*tamanho)++] = num % 2;
}

int main() {
    //input do usuário
    int entrada;
    printf("Entrada: ");
    scanf("%d", &entrada);

    // Declara e inicializa uma lista
    int lista[1000];
    int tamanho = 0;

    // Chama a função
    binario(entrada, lista, &tamanho);
    printf("Binario: ");

    // Imprime o número em binário
    for (int i = 0; i < tamanho; i++) {
      printf("%d", lista[i]);
    }
}

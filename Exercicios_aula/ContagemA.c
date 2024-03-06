#include <stdio.h>

int main() {
    char frase[1000];
    int count = 0;
    int primeiro = -1;
    int ultimo = -1;
    
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin); // Lê a frase do usuário
    
    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] == 'a' || frase[i] == 'A') {
            count++;
            if (primeiro == -1){
              primeiro = i;
            }
            ultimo = i;
        }
    }
    
    printf("Número de letras 'A' na frase: %d\n", count);
    printf("O primeiro 'A' esta na posicao: %d\n", primeiro);
    printf("O ultimo 'A' esta na posicao: %d", ultimo);
    
    return 0;
}

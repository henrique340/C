#include <stdio.h>
#include <math.h>
#include <locale.h>

typedef struct {
    int raio;
    int angulo;
} polar;

typedef struct {
    int x;
    int y;
} coordenadas;

coordenadas converter_coordenadas(polar valor) {
    coordenadas result;
    result.x = valor.raio * cos(valor.angulo);
    result.y = valor.raio * sin(valor.angulo);
    return result;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int r, a;
    printf("Digite o raio: ");
    scanf("%d", &r);
    printf("Digite o angulo: ");
    scanf("%d", &a);
    
    polar valores;
    
    valores.raio = r;
    valores.angulo = a;
    
    coordenadas valor_final = converter_coordenadas(valores);
    printf("A coordenada x � %d e o y � %d", valor_final.x, valor_final.y);
    
    return 0;
}


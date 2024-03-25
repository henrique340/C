#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int particiona(int vetor[], int p, int r) {
    int x = vetor[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (vetor[j] <= x) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[r];
    vetor[r] = temp;
    return i + 1;
}

void quickSort(int vetor[],int p, int r){
	if (p<r){
		int q = particiona(vetor, p, r);
		quickSort(vetor, p, q-1);
		quickSort(vetor, q+1, r);
	}
}

void desce_Heap(int vetor[], int n, int i) {
    while (2 * i <= n) {
        int f = 2 * i;
        if (f < n && vetor[f + 1] > vetor[f])
            f++;
        if (vetor[i] < vetor[f]) {
            int temp = vetor[i];
            vetor[i] = vetor[f];
            vetor[f] = temp;
            i = f;
        } else {
            break;
        }
    }
}

int extrai_Maximo_Heap(int vetor[], int *n) {
    int max = vetor[1];
    vetor[1] = vetor[*n];
    (*n)--;
    desce_Heap(vetor, *n, 1);
    return max;
}

void constroi_Heap(int vetor[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        desce_Heap(vetor, n, i);
    }
}

void heapSort(int vetor[], int n) {
    constroi_Heap(vetor, n);
    int tamanho = n;
    for (int i = n; i >= 2; i--) {
    	int temp = vetor[i];
    	vetor[i] = vetor[1];
    	vetor[1] = temp;
        tamanho--;
        desce_Heap(vetor, tamanho, 1);
    }
}

void merge(int vetor[], int p, int q, int r){
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
 
    // Criação de vetores temporários
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = vetor[p + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[q + 1 + j];
 
    // Juntar os vetores temporários
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }
 
    //copia o resto dos elementos restantes de L[]
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }
 
	//copia o resto dos elementos restantes de R[]
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int vetor[], int p, int r){
    if (p < r) {
        int q = p + (r - p) / 2;
        mergeSort(vetor, p, q);
        mergeSort(vetor, q + 1, r);
        merge(vetor, p, q, r);
    }
}

// Função para gerar valores aleatórios para o vetor
void vetorAleatorio(int vetor[], int tam){
  srand(time(NULL));
  for (int i = 0; i < tam; i++)
  {
    vetor[i] = rand() % 100; // Valores aleatórios de 0 a 100
  }
}

// Função que printa o vetor
void imprimirVetor(int vetor[], int tam){
  for (int i = 0; i < tam; i++)
  {
    printf("%d ",vetor[i]);
  }
  printf("\n");
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	// Menu
	int vetor[1000];
	int opc;
	printf("Algoritimos de ordenação\n\n1 - Merge Sort\n2 - Quick Sort\n3 - Heap Sort");
	printf("\nDigite a sua opção: ");
	scanf("%d", &opc);
	switch (opc) {
		case 1:
			vetorAleatorio(vetor, 100);
	        printf("\nO vetor gerado aleatoriamente fica assim: ");
	        imprimirVetor(vetor, 100);
	        printf("\nO vetor ordenado por Insertion Sort fica assim: ");
	        mergeSort(vetor,0, 100);
	        imprimirVetor(vetor, 100);
	        break;
	        
	    case 2:
			vetorAleatorio(vetor, 100);
	        printf("\nO vetor gerado aleatoriamente fica assim: ");
	        imprimirVetor(vetor, 100);
	        printf("\nO vetor ordenado por Insertion Sort fica assim: ");
	        quickSort(vetor,0, 100);
	        imprimirVetor(vetor, 100);
	        break;
	        
	    case 3:
			vetorAleatorio(vetor, 100);
	        printf("\nO vetor gerado aleatoriamente fica assim: ");
	        imprimirVetor(vetor, 100);
	        printf("\nO vetor ordenado por Insertion Sort fica assim: ");
	        heapSort(vetor, 100);
	        imprimirVetor(vetor, 100);
	        break;
	        
	    default:
	    	printf("\nOpção não reconhecida\n");
	    	return 1;
	}
		
}

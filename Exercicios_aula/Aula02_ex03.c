#include <stdio.h>

typedef struct{
	char nome[50];
	int matricula;
	float nota1;
	float nota2;
}Aluno;

int main(){
	Aluno alunos[100];
	int qnt, i;
	printf("Digite a quantidade de alunos que deseja matricular: ");
	scanf("%d", &qnt);
	for (i=0; i<qnt; i++){
		printf("Aluno %d\n", i+1);
		printf("Nome: ");
		scanf("%s", &alunos[i].nome);
		printf("Matr�cula: ");
		scanf("%d", &alunos[i].matricula);
		printf("Nota 1: ");
		scanf("%f", &alunos[i].nota1);
		printf("Nota 2: ");
		scanf("%f", &alunos[i].nota2);
	}
	printf("--------------\n");
	printf("Resulto\n");
	printf("--------------\n");
	for (i=0; i<qnt; i++){
		printf("Aluno: %d\n", i+1);
		printf("Nome: %s ", alunos[i].nome);
		printf("Matr�cula: %d ", alunos[i].matricula);
		printf("Nota 1: %.2f ", alunos[i].nota1);
		printf("Nota 2: %.2f \n", alunos[i].nota2);
		printf("---------------------\n");
	}
}

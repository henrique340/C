#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definição da estrutura Aluno
typedef struct {
  char turma; // turma: A, B, C ou D
  unsigned int matricula;
  float nota;
} Aluno;

// Função para comparar dois alunos pelo número de matrícula
int comparaMatricula(const void *a, const void *b) {
  const Aluno *alunoA = (const Aluno *)a;
  const Aluno *alunoB = (const Aluno *)b;
  if (alunoA->turma != alunoB->turma) {
    return alunoA->turma - alunoB->turma;
  } else {
    return alunoA->matricula - alunoB->matricula;
  }
}

// Função para comparar dois alunos pela nota (em ordem decrescente)
int comparaNota(const void *a, const void *b) {
  const Aluno *alunoA = (const Aluno *)a;
  const Aluno *alunoB = (const Aluno *)b;
  if (alunoA->nota < alunoB->nota) {
    return 1;
  } else if (alunoA->nota > alunoB->nota) {
    return -1;
  } else {
    return 0;
  }
}

int main() {
  setlocal(LC_ALL, "Portuguese");
  FILE *arquivo;
  int n;

  // Abre o arquivo para leitura
  arquivo = fopen("alunos.txt", "r");
  if (arquivo == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo.\n");
    return 1;
  }

  // Lê o número inicial
  fscanf(arquivo, "%d", &n);

  // Aloca dinamicamente o vetor de alunos
  Aluno *alunos = (Aluno *)malloc(n * sizeof(Aluno));
  if (alunos == NULL) {
    fprintf(stderr, "Erro de alocação de memória.\n");
    fclose(arquivo);
    return 1;
  }

  // Lê os dados dos alunos do arquivo
  for (int i = 0; i < n; i++) {
    fscanf(arquivo, " %c %u %f", &alunos[i].turma, &alunos[i].matricula, &alunos[i].nota);
  }

  // Fecha o arquivo
  fclose(arquivo);


  // Menu de opções
  int opcao;
  do {
    printf("\nEscolha uma opcao:\n");
    printf("1. Ordenado por turma e matricula\n");
    printf("2. Ordenado por nota\n");
    printf("3. Mostrar alunos de uma turma em ordem de matricula\n");
    printf("4. Mostrar alunos de uma turma em ordem decrescente de nota\n");
    printf("0. Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    // Opcoes
    switch (opcao) {
      // Ordena os alunos por turma e matrícula
      case 1:
        qsort(alunos, n, sizeof(Aluno), comparaMatricula);

        // Exibe os alunos ordenados
        printf("\nAlunos ordenados por turma e matricula:\n");
        for (int i = 0; i < n; i++) {
          printf("%c %d %.2f\n", alunos[i].turma, alunos[i].matricula, alunos[i].nota);
        }
        break;

      // Ordena os alunos por nota
      case 2:
        qsort(alunos, n, sizeof(Aluno), comparaNota);

        // Exibe os alunos ordenados
        printf("\nAlunos ordenados por nota:\n");
        for (int i = 0; i < n; i++) {
          printf("%c %d %.2f\n", alunos[i].turma, alunos[i].matricula, alunos[i].nota);
        }
        break;
      
      // Mostra alunos de uma turma em ordem de matricula
      case 3:
        {
          char turma;
          printf("\nDigite a turma: ");
          scanf(" %c", &turma);
          printf("Alunos da turma %c em ordem de matricula:\n", turma);
          for (int i = 0; i < n; i++) {
            if (alunos[i].turma == turma) {
              printf("%c %d %.2f\n", alunos[i].turma, alunos[i].matricula, alunos[i].nota);
            }
          }
        }
        break;
      
      // Mostra alunos de uma turma em ordem decrescente de nota
      case 4:
        {
          char turma;
          printf("\nDigite a turma: ");
          scanf(" %c", &turma);
          printf("Alunos da turma %c em ordem decrescente de nota:\n", turma);
          for (int i = 0; i < n; i++) {
            if (alunos[i].turma == turma) {
              printf("%c %d %.2f\n", alunos[i].turma, alunos[i].matricula, alunos[i].nota);
            }
          }
        }
        break;
      
      // Saindo do programa
      case 0:
        printf("Saindo...\n");
        break;

      default:
        printf("Opcao invalida.\n");
    }
  } while (opcao != 0);

  // Libera a memória alocada
  free(alunos);

  return 0;
}

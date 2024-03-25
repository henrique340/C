#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definição do objeto Aluno
typedef struct {
    char turma; // turma: A, B, C ou D
    unsigned int matricula;
    float nota;
} Aluno;

// Função para ler os dados dos alunos de um arquivo
int lerAlunos(Aluno **alunos, const char *nomeArquivo) {
  FILE *arquivo;
  int n;

  // Abre o arquivo para leitura
  arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo.\n");
    return -1;
  }

  // Lê o número de registros
  fscanf(arquivo, "%d", &n);

  // Aloca dinamicamente o vetor de alunos
  *alunos = (Aluno *)malloc(n * sizeof(Aluno));
  if (*alunos == NULL) {
    fprintf(stderr, "Erro de alocacao de memoria.\n");
    fclose(arquivo);
    return -1;
  }

  // Lê os dados dos alunos do arquivo
  for (int i = 0; i < n; i++) {
    fscanf(arquivo, " %c %u %f", &((*alunos)[i].turma), &((*alunos)[i].matricula), &((*alunos)[i].nota));
  }

  // Fecha o arquivo
  fclose(arquivo);

  return n;
}

// Função para exibir os alunos
void exibirAlunos(Aluno *alunos, int n) {
  printf("Turma Matricula Nota\n");
  for (int i = 0; i < n; i++) {
    printf("%c %u %.2f\n", alunos[i].turma, alunos[i].matricula, alunos[i].nota);
  }
}

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
  setlocale(LC_ALL, "Portuguese");
  Aluno *alunos;
  int n = lerAlunos(&alunos, "alunos.txt");
  if (n == -1) {
    return 1;
  }

  int opcao;
  do {
    // Menu de opções
    printf("\nEscolha uma opcao:\n");
    printf("1. Ordenado por turma e matricula\n");
    printf("2. Ordenado por nota\n");
    printf("3. Mostrar alunos de uma turma em ordem de matricula\n");
    printf("4. Mostrar alunos de uma turma em ordem decrescente de nota\n");
    printf("0. Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        // Ordena os alunos por turma e matrícula
        qsort(alunos, n, sizeof(Aluno), comparaMatricula);
        // Exibe os alunos ordenados
        printf("\nAlunos ordenados por turma e matricula:\n");
        exibirAlunos(alunos, n);
        break;
      case 2:
        // Ordena os alunos por nota
        qsort(alunos, n, sizeof(Aluno), comparaNota);
        // Exibe os alunos ordenados
        printf("\nAlunos ordenados por nota:\n");
        exibirAlunos(alunos, n);
        break;
      case 3:
        // Mostra alunos de uma turma em ordem de matricula
        {
        char turma;
        printf("\nDigite a turma: ");
        scanf(" %c", &turma);
        printf("Alunos da turma %c em ordem de matricula:\n", turma);
        for (int i = 0; i < n; i++) {
          if (alunos[i].turma == turma) {
            printf("%c %u %.2f\n", alunos[i].turma, alunos[i].matricula, alunos[i].nota);
          }
        }
        }
        break;
      case 4:
        // Mostra alunos de uma turma em ordem decrescente de nota
        {
        char turma;
        printf("\nDigite a turma: ");
        scanf(" %c", &turma);
        printf("Alunos da turma %c em ordem decrescente de nota:\n", turma);
        for (int i = 0; i < n; i++) {
          if (alunos[i].turma == turma) {
            printf("%c %u %.2f\n", alunos[i].turma, alunos[i].matricula, alunos[i].nota);
          }
        }
        }
        break;
      case 0:
        printf("Saindo...\n");
        break;
      default:
        printf("Opcao invalida.\n");
    }
  } while (opcao != 0);

  free(alunos);

  return 0;
}

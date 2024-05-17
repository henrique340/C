// Bibliotecas usadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Função para gerar uma entrada aleatória
void gerarEntrada(int num, char nome[]){
  for (int i = 0; i < num; i++){
    // Criando o arquivo entrada.csv
    FILE *arquivo = fopen(nome, "a");
    if (arquivo == NULL){
      fprintf(stderr, "Erro ao abrir arquivo!");
      return;
    }
    // Gerando numeros aleatorios
    int ano = (rand() % 27) + 2010;     // Retorna um numero entre 2010 e 2026
    int mes = (rand() % 12) + 1;        // Retorna um numero entre 1 e 12
    int dia = (rand() % 31) + 1;        // Retorna um numero entre 1 e 31
    int hora = (rand() % 24) + 0;       // Retorna um numero entre 0 e 24
    int minuto = (rand() % 60) + 0;     // Retorna um numero entre 0 e 60
    int duracao = (rand() % 13) + 1;    // Retorna um numero entre 1 e 13
    char *nomes[] = {"Aula", "TCC", "Webnar", "Natacao", "Reuniao"};
    int indice = rand() % 5;
    char *nome = nomes[indice];

    fprintf(arquivo, "%d;%d;%d;%d;%d;%d;%s\n", ano, mes, dia, hora, minuto, duracao, nome);
    fclose(arquivo);
  }
}

// Função para usar o algoritimo Insertion Sort
void insertionSort(char nome[]){
  // Declaração do tipo long long int
  unsigned long long int comparacoes = 0;
  // Declaracao das variaveis de tempo
  double tempo_execucao;
  clock_t start, end;

  FILE *arquivo = fopen(nome, "r");
  if (arquivo == NULL){
    fprintf(stderr, "Erro ao abrir arquivo!");
    return;
  }

  // Contador de linhas
  int linhas = 0;
  char linha[100]; // Tamanho máximo de uma linha
  while (fgets(linha, sizeof(linha), arquivo) != NULL){
    linhas++;
  }
  rewind(arquivo); // Volta para o início do arquivo

  // Armazenando os dados em arrays com alocacao de memoria
  int *anos = malloc(linhas * sizeof(int));
  if (anos == NULL){
    fprintf(stderr, "Erro ao alocar memoria");
    fclose(arquivo);
    return;
  }
  int *meses = malloc(linhas * sizeof(int));
  int *dias = malloc(linhas * sizeof(int));
  int *horas = malloc(linhas * sizeof(int));
  int *minutos = malloc(linhas * sizeof(int));
  int *duracoes = malloc(linhas * sizeof(int));
  char **nomes = malloc(linhas * sizeof(char *));
  for (int i = 0; i < linhas; i++){
    nomes[i] = malloc(20 * sizeof(char));
  }

  // Leitura dos dados
  for (int i = 0; i < linhas; i++){
    fscanf(arquivo, "%d;%d;%d;%d;%d;%d;%s", &anos[i], &meses[i], &dias[i], &horas[i], &minutos[i], &duracoes[i], nomes[i]);
  }

  // Inicia o clock
  start = clock();

  // Algoritmo de Insertion Sort para ordenar os dados por ano
  for (int i = 1; i < linhas; i++) {
    int anoChave = anos[i];
    int mesChave = meses[i];
    int diaChave = dias[i];
    int horaChave = horas[i];
    int minutoChave = minutos[i];
    int duracaoChave = duracoes[i];
    char nomeChave[20];
    strcpy(nomeChave, nomes[i]);

    int j = i - 1;
    while (j >= 0 && anos[j] > anoChave) {
      comparacoes++;
      anos[j + 1] = anos[j];
      meses[j + 1] = meses[j];
      dias[j + 1] = dias[j];
      horas[j + 1] = horas[j];
      minutos[j + 1] = minutos[j];
      duracoes[j + 1] = duracoes[j];
      strcpy(nomes[j + 1], nomes[j]);
      j = j - 1;
    }
    anos[j + 1] = anoChave;
    meses[j + 1] = mesChave;
    dias[j + 1] = diaChave;
    horas[j + 1] = horaChave;
    minutos[j + 1] = minutoChave;
    duracoes[j + 1] = duracaoChave;
    strcpy(nomes[j + 1], nomeChave);
  }

  // Fim do clock
  end = clock();
  tempo_execucao = ((double) (end - start)) / CLOCKS_PER_SEC;

  fclose(arquivo);

  // Escrevendo os dados ordenados de volta no arquivo//

  arquivo = fopen("saida.csv", "w");
  if (arquivo == NULL){
    fprintf(stderr, "Erro ao abrir arquivo de saída!");
    return;
  }

  for (int i = 0; i < linhas; i++){
    fprintf(arquivo, "%d;%d;%d;%d;%d;%d;%s\n", anos[i], meses[i], dias[i], horas[i], minutos[i], duracoes[i], nomes[i]);
  }

  fclose(arquivo);

  // Removendo o arquivo original
  if (remove("entrada.csv") != 0){
    printf("Erro ao remover arquivo original\n");
  }

  // Renomear o arquivo temp para entrada.csv
  if (rename("saida.csv", "entrada.csv") != 0){
    printf("Erro ao renomear arquivo temp");
    return;
  }
  
  // Liberando a memória alocada
  free(anos);
  free(meses);
  free(dias);
  free(horas);
  free(minutos);
  free(duracoes);
  for (int i = 0; i < linhas; i++){
    free(nomes[i]);
  }
  free(nomes);

  printf("Algoritimo: Insertion Sort\nTamanho Entrada: %d\nTempo de execucao: %.3f segundos\nComparacoes (passos): %llu", linhas, tempo_execucao, comparacoes);
  
}


// Função para usar o algorítimo Quick Sort
void quickSort(char nome[]){
  unsigned long long int comparacoes = 0;
  double tempo_execucao;
  clock_t start, end;

  FILE *arquivo = fopen(nome, "r");
  if (arquivo == NULL){
    fprintf(stderr, "Erro ao abrir arquivo!");
    return;
  }

  // Contador de linhas
  int linhas = 0;
  char linha[100]; // Tamanho máximo de uma linha
  while (fgets(linha, sizeof(linha), arquivo) != NULL){
    linhas++;
  }
  rewind(arquivo); // Volta para o início do arquivo

  // Lendo os dados e armazenando em arrays
  int *anos = malloc(linhas * sizeof(int));
  if (anos == NULL) {
    fprintf(stderr, "Erro ao alocar memória!");
    fclose(arquivo);
    return;
  }
  int *meses = malloc(linhas * sizeof(int));
  int *dias = malloc(linhas * sizeof(int));
  int *horas = malloc(linhas * sizeof(int));
  int *minutos = malloc(linhas * sizeof(int));
  int *duracoes = malloc(linhas * sizeof(int));
  char **nomes = malloc(linhas * sizeof(char *));
  for (int i = 0; i < linhas; i++) {
    nomes[i] = malloc(20 * sizeof(char));
  }
  for (int i = 0; i < linhas; i++){
    fscanf(arquivo, "%d;%d;%d;%d;%d;%d;%s", &anos[i], &meses[i], &dias[i], &horas[i], &minutos[i], &duracoes[i], nomes[i]);
  }

  start = clock();

  // Algoritmo de Quick Sort para ordenar os dados por ano
  void quickSortRecursivo(int low, int high) {
    if (low < high) {
      int pivot = anos[high];
      int i = low - 1;

      for (int j = low; j < high; j++) {
        comparacoes++;
        if (anos[j] < pivot) {
          i++;
          // Troca os elementos
          int tempAno = anos[i];
          anos[i] = anos[j];
          anos[j] = tempAno;

          int tempMes = meses[i];
          meses[i] = meses[j];
          meses[j] = tempMes;

          int tempDia = dias[i];
          dias[i] = dias[j];
          dias[j] = tempDia;

          int tempHora = horas[i];
          horas[i] = horas[j];
          horas[j] = tempHora;

          int tempMinuto = minutos[i];
          minutos[i] = minutos[j];
          minutos[j] = tempMinuto;

          int tempDuracao = duracoes[i];
          duracoes[i] = duracoes[j];
          duracoes[j] = tempDuracao;

          char tempNome[20];
          strcpy(tempNome, nomes[i]);
          strcpy(nomes[i], nomes[j]);
          strcpy(nomes[j], tempNome);
        }
      }

      // Troca os elementos
      int tempAno = anos[i + 1];
      anos[i + 1] = anos[high];
      anos[high] = tempAno;

      int tempMes = meses[i + 1];
      meses[i + 1] = meses[high];
      meses[high] = tempMes;

      int tempDia = dias[i + 1];
      dias[i + 1] = dias[high];
      dias[high] = tempDia;

      int tempHora = horas[i + 1];
      horas[i + 1] = horas[high];
      horas[high] = tempHora;

      int tempMinuto = minutos[i + 1];
      minutos[i + 1] = minutos[high];
      minutos[high] = tempMinuto;

      int tempDuracao = duracoes[i + 1];
      duracoes[i + 1] = duracoes[high];
      duracoes[high] = tempDuracao;

      char tempNome[20];
      strcpy(tempNome, nomes[i + 1]);
      strcpy(nomes[i + 1], nomes[high]);
      strcpy(nomes[high], tempNome);

      int pi = i + 1;

      quickSortRecursivo(low, pi - 1);
      quickSortRecursivo(pi + 1, high);
    }
  }

  quickSortRecursivo(0, linhas - 1);

  end = clock();
  tempo_execucao = ((double) (end - start)) / CLOCKS_PER_SEC;

  fclose(arquivo);

  // Escrevendo os dados ordenados de volta no arquivo
  arquivo = fopen("saida.csv", "w");
  if (arquivo == NULL){
    fprintf(stderr, "Erro ao abrir arquivo de saída!");
    return;
  }

  for (int i = 0; i < linhas; i++){
    fprintf(arquivo, "%d;%d;%d;%d;%d;%d;%s\n", anos[i], meses[i], dias[i], horas[i], minutos[i], duracoes[i], nomes[i]);
  }

  fclose(arquivo);

  // Removendo o arquivo original
  if (remove("entrada.csv") != 0){
    printf("Erro ao remover arquivo original\n");
  }

  // Renomear o arquivo temp para entrada.csv
  if (rename("saida.csv", "entrada.csv") != 0){
    printf("Erro ao renomear arquivo temp");
    return;
  }
  free(anos);
  free(meses);
  free(dias);
  free(horas);
  free(minutos);
  free(duracoes);
  for (int i = 0; i < linhas; i++){
    free(nomes[i]);
  }
  free(nomes);

  printf("Algoritimo: Quick Sort\nTamanho Entrada: %d\nTempo de execucao: %.3f segundos\nComparacoes (passos): %llu", linhas, tempo_execucao, comparacoes);
}

int main(){
  int opc;
  do {
    printf("\n------------------------------------\n");
    printf("\t\tMenu\t\t");
    printf("\n------------------------------------\n");
    printf("[1] - Gerar entrada aleatoria\n");
    printf("[2] - Ordenar por ano (Insertion Sort)\n");
    printf("[3] - Ordenar por ano (Quick Sort)\n");
    printf("[4] - Sair");
    printf("\nDigite a sua opcao: ");
    scanf("%d", &opc);

    // ------------------------------------ //
    //                Menu                  //
    // ------------------------------------ //

    srand(time(NULL));
    switch (opc)
    {
    case 1:
      gerarEntrada(6000, "entrada.csv");
      break;
    case 2:
      insertionSort("entrada.csv");
      break;
    case 3:
      quickSort("entrada.csv");
      break;
    case 4:
      printf("Saindo do programa ...");
      break;
    default:
      printf("Digite uma opcao valida!");
      break;
    }
  } while (opc != 4);
}

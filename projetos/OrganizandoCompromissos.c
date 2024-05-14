// Henrique Yuji Isogai Yoneoka
// RA: 10418153


// Bibliotecas usadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// Não usei struct porque achei uma função em C que faz a função muito mais simples

/*
typedef struct
{
  int ano;
  int mes;
  int dia;
  int hora;
  int minuto;
  int duracao;
  int indice;
  char nome[];
} compromisso
*/

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
    int mes = (rand() % 13) + 1;        // Retorna um numero entre 1 e 12
    int dia = (rand() % 32) + 1;        // Retorna um numero entre 1 e 31
    int hora = (rand() % 25) + 0;       // Retorna um numero entre 0 e 24
    int minuto = (rand() % 61) + 0;     // Retorna um numero entre 0 e 60
    int duracao = (rand() % 13) + 1;    // Retorna um numero entre 1 e 13

    char *nomes[] = {"Aula", "TCC", "Webnar", "Natacao", "Reuniao"};
    int indice = rand() % 5;
    char *nome = nomes[indice];

    fprintf(arquivo, "%d;%d;%d;%d;%d;%d;%s\n", ano, mes, dia, hora, minuto, duracao, nome);
    fclose(arquivo);
  }
}


// Função para usar o algoritimo Insertion Sort
void insertionSort(char nome[], bool mostrar_info, bool mostrar_media_DV){
  int comparacoes = 0;
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
  int anos[linhas], meses[linhas], dias[linhas], horas[linhas], minutos[linhas], duracoes[linhas];
  char nomes[linhas][20]; // Tamanho máximo do nome
  for (int i = 0; i < linhas; i++){
    fscanf(arquivo, "%d;%d;%d;%d;%d;%d;%s", &anos[i], &meses[i], &dias[i], &horas[i], &minutos[i], &duracoes[i], nomes[i]);
  }

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

  end = clock();
  tempo_execucao = ((double) (end - start)) / CLOCKS_PER_SEC;

  // Calcula a media do tempo de execução
  double media = 0.0;
  for (int i = 0; i < linhas; i++) {
    media += tempo_execucao;
  }
  media /= linhas;

  // Calcula o DV do tempo de execução
  double soma_quadrados_diff = 0.0;
  for (int i = 0; i < linhas; i++) {
    double diff = tempo_execucao - media;
    soma_quadrados_diff += diff * diff;
  }
  double media_quadrados_diff = soma_quadrados_diff / linhas;
  double desvio_padrao = sqrt(media_quadrados_diff);

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
  if (remove("entrada2.csv") != 0){
    printf("Erro ao remover arquivo original\n");
  }

  // Renomear o arquivo temp para entrada.csv
  if (rename("saida.csv", "entrada2.csv") != 0){
    printf("Erro ao renomear arquivo temp");
    return;
  }
  if (mostrar_info){
    printf("Algoritimo: Quick Sort\nTamanho Entrada: %d\nTempo de execucao: %f segundos\nComparacoes (passos): %d", linhas, tempo_execucao, comparacoes);
  }
  if (mostrar_media_DV){
    printf("media: %.2f|DV:%.2f", media, desvio_padrao);
  }
}


// Função para usar o algorítimo Quick Sort
void quickSort(char nome[], bool mostrar_info, bool mostrar_media_DV){
  int comparacoes = 0;
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
  int anos[linhas], meses[linhas], dias[linhas], horas[linhas], minutos[linhas], duracoes[linhas];
  char nomes[linhas][20]; // Tamanho máximo do nome
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

  // Calcula o desvio padrão dos tempos de execução
  double media = 0.0;
  for (int i = 0; i < linhas; i++) {
    media += tempo_execucao;
  }
  media /= linhas;

  double soma_quadrados_diff = 0.0;
  for (int i = 0; i < linhas; i++) {
    double diff = tempo_execucao - media;
    soma_quadrados_diff += diff * diff;
  }
  double media_quadrados_diff = soma_quadrados_diff / linhas;
  double desvio_padrao = sqrt(media_quadrados_diff);

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
  if (remove("entrada2.csv") != 0){
    printf("Erro ao remover arquivo original\n");
  }

  // Renomear o arquivo temp para entrada.csv
  if (rename("saida.csv", "entrada2.csv") != 0){
    printf("Erro ao renomear arquivo temp");
    return;
  }

  if (mostrar_info){
    printf("Algoritimo: Quick Sort\nTamanho Entrada: %d\nTempo de execucao: %.2f segundos\nComparacoes (passos): %d", linhas, tempo_execucao, comparacoes);
  }
  if (mostrar_media_DV){
    printf("media: %.2f|DV: %.2f       |",media, desvio_padrao);
  }
}


void copiarArquivo(char origem[], char destino[]){
  FILE *arquivoOrigem = fopen(origem, "r");
  if (arquivoOrigem == NULL){
    fprintf(stderr, "Erro ao abrir arquivo!");
    fclose(arquivoOrigem);
    return;
  }

  FILE *arquivoDestino = fopen(destino, "w");
  if (arquivoDestino == NULL){
    fprintf(stderr, "Erro ao abrir arquivo!");
    return;
  }
  char linha[1000];
  while (fgets(linha, sizeof(linha), arquivoOrigem) != NULL){
    fputs(linha, arquivoDestino);
  }
  fclose(arquivoOrigem);
  fclose(arquivoDestino);
}


void analiseAlgoritimos(){
  // 1.000
  gerarEntrada(1000, "tabela1.csv");
  copiarArquivo("tabela1.csv", "tabela2.csv");
  printf("Tebela 1 - Tempo (em segundos)\n");
  printf("----------------------------------------------------------------------------------------\n");
  printf("|  Alunos  |  Insertion sort  |  Insertion sort  |    Quick sort    |    Quick sort    |\n");
  printf("|          |  medido (Media)  |    medido (DV)   |   medido(Media)  |    medido (DV)   |\n");
  printf("----------------------------------------------------------------------------------------\n");
  printf("|  1.000   |");
  insertionSort("tabela1.csv",false, true);
  quickSort("tabela2.csv",false, true);
  printf("\n----------------------------------------------------------------------------------------\n");
  

  // 10.000
  gerarEntrada(10000, "tabela1.csv");
  copiarArquivo("tabela1.csv","tabela2.csv");
  printf("|  10.000  |");
  insertionSort("tabela1.csv", false, true);
  quickSort("tabela2.csv", false, true);
  printf("\n----------------------------------------------------------------------------------------\n");
  remove("tabela1.csv");
  remove("tabela2.csv");

  // 100.000
  gerarEntrada(100000, "tabela1.csv");
  copiarArquivo("tabela1.csv", "tabela2.csv");
  printf("----------------------------------------------------------------------------------------\n");
  printf("| 100.000  |");
  insertionSort("tabela1.csv", false, true);
  quickSort("tabela2.csv", false, true);
  printf("\n----------------------------------------------------------------------------------------\n");
  remove("tabela1.csv");
  remove("tabela2.csv");

  // 200.000
  gerarEntrada(200000, "tabela1.csv");
  copiarArquivo("tabela1.csv", "tabela2.csv");
  printf("----------------------------------------------------------------------------------------\n");
  printf("| 200.000  |");
  insertionSort("tabela1.csv", false, true);
  quickSort("tabela2.csv", false, true);
  printf("----------------------------------------------------------------------------------------\n");


  /*      COMPARACOES      */
  printf("\nTebela 2 - Comparacoes\n");
  printf("----------------------------------------------------------------------------------------\n");
  printf("|   Alunos   |   Insertion   |   Insertion   |    Quick    |    Quick    |    Quick    |\n");
  printf("|            |     sort      |     sort      |    sort     |    sort     |    sort     |\n");
  printf("|            |     medido    |     medido    |    teorico  |    medido   |    medido   |\n");
  printf("|            |    (media)    |     (DV)      |   (O(n^2))  |    (media)  | (O(n log n))|\n");
  printf("----------------------------------------------------------------------------------------\n");
  printf("|    1000    |               |               |             |             |             |\n");
  printf("----------------------------------------------------------------------------------------\n");
  printf("|    1000    |               |               |             |             |             |\n");
  printf("----------------------------------------------------------------------------------------\n");
  printf("|    1000    |               |               |             |             |             |\n");
  printf("----------------------------------------------------------------------------------------\n");
  printf("|    1000    |               |               |             |             |             |\n");
  printf("----------------------------------------------------------------------------------------\n");

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
    printf("[4] - Gerar tabela\n");
    printf("[5] - Sair");
    printf("\nDigite a sua opcao: ");
    scanf("%d", &opc);

    // ------------------------------------ //
    //                Menu                  //
    // ------------------------------------ //

    srand(time(NULL));
    switch (opc)
    {
    case 1:
      gerarEntrada(1000, "entrada2.csv");
      break;
    case 2:
      insertionSort("entrada2.csv", false, true);
      break;
    case 3:
      quickSort("entrada2.csv", false, true);
      break;
    case 4:
      analiseAlgoritimos();
      break;
    case 5:
      printf("Saindo do programa ...");
      break;
    default:
      printf("Digite uma opcao valida!");
      break;
    }
  } while (opc != 5);
}


/*DUVIDA: 
  O que o enunciado quis dizer com faça 10 vezes e faça a média?
  É pra eu fazer por mim 10 vezes ou o código?
  Eu posso fazer em excel ou precisa ser feito usando alguma biblioteca da própria linguagem?
*/

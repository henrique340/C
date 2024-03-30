// NOME: Henrique Yuji Isogai Yoneoka RA: 10418153

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int ano;
  int mes;
  int dia;
  int hora;
  int minuto;
  int duracao;
  int prioridade;
  char nomeCompromisso[100];
  char descricao[100];
  char local[100];
} Compromisso;

// Função para adicionar um compromisso
void adicionarCompromisso(char *nomeArquivo, int ano, int mes, int dia, int hora, int minuto, int duracao, int prioridade, char *nomeCompromisso, char *descricao, char *local)
{
  FILE *arquivo = fopen(nomeArquivo, "a"); // Abre o arquivo no modo de escrita

  if (arquivo == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo\n");
    return;
  }

  fprintf(arquivo, "%d;%d;%d;%d;%d;%d;%d;%s;%s;%s\n", ano, mes, dia, hora, minuto, duracao, prioridade, nomeCompromisso, descricao, local);
  fclose(arquivo);
}

// Função remover compromisso
void removerCompromisso()
{
  FILE *arquivo = fopen("entrada.csv", "r");

  if (arquivo == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo\n");
    return;
  }

  // Mostrar a lista de compromissos para o usuário
  printf("--------------------------");
  printf(" Lista de Compromissos");
  printf("--------------------------\n");
  int contador = 0;
  char linha[100];
  while (fgets(linha, sizeof(linha), arquivo) != NULL)
  {
    printf("[%d] - %s", contador, linha);
    contador++;
  }
  fclose(arquivo);

  // Input do usuário
  printf("\nDigite a linha da sua escolha: ");
  int indice;
  scanf("%d", &indice);

  // Abrir o arquivo no modo escrita
  arquivo = fopen("entrada.csv", "r");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir arquivo");
    return;
  }

  // Criar um arquivo temporário para transferir todas menos a linha do input do usuário
  FILE *arquivoTemp = fopen("temp.csv", "w");

  if (arquivoTemp == NULL)
  {
    printf("Erro ao abrir o arquivo temp.csv");
    fclose(arquivo);
    return;
  }

  /* Copiando todos os compromissos do arquivo para o arquivoTemp
  exceto o que o usuário quer remover */
  contador = 0;
  while (fgets(linha, sizeof(linha), arquivo) != NULL)
  {
    if (contador != indice)
    {
      fputs(linha, arquivoTemp); // exclui o compromisso
    }
    contador++;
  }
  fclose(arquivo);
  fclose(arquivoTemp);

  // Removendo o arquivo original
  if (remove("entrada.csv") != 0)
  {
    printf("Erro ao remover arquivo original\n");
  }

  // Renomear o arquivo temp para entrada.csv
  if (rename("temp.csv", "entrada.csv") != 0)
  {
    printf("Erro ao renomear arquivo temp");
    return;
  }
  printf("\nCompromisso removido com sucesso\n");
}




// Função para ordenar por data em ordem crescente
void ordenarData()
{
  FILE *arquivo = fopen("entrada.csv", "r");

  if (arquivo == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo\n");
    return;
  }

  int numCompromissos = 0;
  Compromisso compromissos[100];
  char line[256];
  while (fgets(line, sizeof(line), arquivo) != NULL){
    if (sscanf(line, "%d;%d;%d;%d;%d;%d;%d;%99[^;];%99[^;];%99[^\n]",
              &compromissos[numCompromissos].ano,
              &compromissos[numCompromissos].mes,
              &compromissos[numCompromissos].dia,
              &compromissos[numCompromissos].hora,
              &compromissos[numCompromissos].minuto,
              &compromissos[numCompromissos].duracao,
              &compromissos[numCompromissos].prioridade,
              compromissos[numCompromissos].nomeCompromisso,
              compromissos[numCompromissos].descricao,
              compromissos[numCompromissos].local) == 10)
    {
      numCompromissos++;
    }
    else
    {
      printf("Erro ao ler linha do arquivo\n");
      // Trate o erro conforme necessário
    }
  }
  fclose(arquivo);

  // Bubble Sort
  /* Só troca as linhas se ano[j] > ano[j+1] ou ,se os anos forem iguais, se o mes[j] > mes[j+1] e assim vai*/
  for (int i = 0; i < numCompromissos - 1; i++)
  {
    for (int j = 0; j < numCompromissos - i - 1; j++)
    {
      if ((compromissos[j].ano > compromissos[j + 1].ano) || (compromissos[j].ano == compromissos[j + 1].ano && compromissos[j].mes > compromissos[j + 1].mes) || (compromissos[j].mes == compromissos[j + 1].mes && compromissos[j].dia > compromissos[j + 1].dia) || (compromissos[j].dia == compromissos[j + 1].dia))
      {
        Compromisso temp = compromissos[j];
        compromissos[j] = compromissos[j + 1];
        compromissos[j + 1] = temp;
      }
    }
  }

  // Criando um arquivo saida.csv
  FILE *arquivoOrdenado = fopen("saida.csv", "w");

  if (arquivoOrdenado == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo\n");
    return;
  }

  // Escrevendo os compromissos no arquivo saida.csv
  for (int i = 0; i < numCompromissos; i++)
  {
    fprintf(arquivoOrdenado, "%d;%d;%d;%d;%d;%d;%d;%s;%s;%s\n",
            compromissos[i].ano,
            compromissos[i].mes,
            compromissos[i].dia,
            compromissos[i].hora,
            compromissos[i].minuto,
            compromissos[i].duracao,
            compromissos[i].prioridade,
            compromissos[i].nomeCompromisso,
            compromissos[i].descricao,
            compromissos[i].local);
  }
  fclose(arquivoOrdenado);

  // Ler o arquivo saida.csv
  arquivo = fopen("saida.csv", "r");
  if (arquivo == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo\n");
    return;
  }

  printf("\n--------------------------");
  printf(" Lista de Compromissos");
  printf("--------------------------\n");
  int contador = 0;
  char linha[100];
  while (fgets(linha, sizeof(linha), arquivo) != NULL)
  {
    printf("[%d] - %s", contador, linha);
    contador++;
  }
  fclose(arquivo);

  // Apagando arquivo saida.csv
  if (remove("saida.csv") != 0)
  {
    printf("Erro ao remover arquivo original\n");
  }
}




void ordenarDataHorario()
{
  FILE *arquivo = fopen("entrada.csv", "r");

  if (arquivo == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo\n");
    return;
  }

  int numCompromissos = 0;
  Compromisso compromissos[100];
  char line[256];
  while (fgets(line, sizeof(line), arquivo) != NULL){
    if (sscanf(line, "%d;%d;%d;%d;%d;%d;%d;%99[^;];%99[^;];%99[^\n]",
              &compromissos[numCompromissos].ano,
              &compromissos[numCompromissos].mes,
              &compromissos[numCompromissos].dia,
              &compromissos[numCompromissos].hora,
              &compromissos[numCompromissos].minuto,
              &compromissos[numCompromissos].duracao,
              &compromissos[numCompromissos].prioridade,
              compromissos[numCompromissos].nomeCompromisso,
              compromissos[numCompromissos].descricao,
              compromissos[numCompromissos].local) == 10)
    {
      numCompromissos++;
    } else {
      printf("Erro ao ler linha do arquivo\n");
      // Trate o erro conforme necessário
    }
  }
  fclose(arquivo);

  // Bubble Sort
  /* Só troca as linhas se ano[j] > ano[j+1] ou ,se os anos forem iguais, se o mes[j] > mes[j+1] e assim vai*/
  for (int i = 0; i < numCompromissos - 1; i++)
  {
    for (int j = 0; j < numCompromissos - i - 1; j++)
    {
      if ((compromissos[j].ano > compromissos[j + 1].ano) || (compromissos[j].ano == compromissos[j + 1].ano && compromissos[j].mes > compromissos[j + 1].mes) || (compromissos[j].mes == compromissos[j + 1].mes && compromissos[j].dia > compromissos[j + 1].dia) || (compromissos[j].dia == compromissos[j + 1].dia && compromissos[j].hora > compromissos[j + 1].hora) || (compromissos[j].hora == compromissos[j + 1].hora && compromissos[j].minuto > compromissos[j + 1].minuto))
      {
        Compromisso temp = compromissos[j];
        compromissos[j] = compromissos[j + 1];
        compromissos[j + 1] = temp;
      }
    }
  }

  // Criando um arquivo entrada.csv
  FILE *arquivoOrdenado = fopen("saida.csv", "w");

  if (arquivoOrdenado == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo\n");
    return;
  }

  // Escrevendo os compromissos no arquivo saida.csv
  for (int i = 0; i < numCompromissos; i++)
  {
    fprintf(arquivoOrdenado, "%d;%d;%d;%d;%d;%d;%d;%s;%s;%s\n",
            compromissos[i].ano,
            compromissos[i].mes,
            compromissos[i].dia,
            compromissos[i].hora,
            compromissos[i].minuto,
            compromissos[i].duracao,
            compromissos[i].prioridade,
            compromissos[i].nomeCompromisso,
            compromissos[i].descricao,
            compromissos[i].local);
  }
  fclose(arquivoOrdenado);

  // Ler o arquivo saida.csv
  arquivo = fopen("saida.csv", "r");
  if (arquivo == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo\n");
    return;
  }

  printf("--------------------------");
  printf(" Lista de Compromissos");
  printf("--------------------------\n");
  int contador = 0;
  char linha[100];
  while (fgets(linha, sizeof(linha), arquivo) != NULL)
  {
    printf("[%d] - %s", contador, linha);
    contador++;
  }
  fclose(arquivo);

  // Apagando arquivo saida.csv
  if (remove("saida.csv") != 0)
  {
    printf("Erro ao remover arquivo original\n");
  }
}



void ordenarDataPrioridade() {
  FILE *arquivo = fopen("entrada.csv", "r");

  if (arquivo == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo\n");
    return;
  }

  int numCompromissos = 0;
  Compromisso compromissos[100];
  char line[256];
  while (fgets(line, sizeof(line), arquivo) != NULL){
    if (sscanf(line, "%d;%d;%d;%d;%d;%d;%d;%99[^;];%99[^;];%99[^\n]",
              &compromissos[numCompromissos].ano,
              &compromissos[numCompromissos].mes,
              &compromissos[numCompromissos].dia,
              &compromissos[numCompromissos].hora,
              &compromissos[numCompromissos].minuto,
              &compromissos[numCompromissos].duracao,
              &compromissos[numCompromissos].prioridade,
              compromissos[numCompromissos].nomeCompromisso,
              compromissos[numCompromissos].descricao,
              compromissos[numCompromissos].local) == 10)
    {
      numCompromissos++;
    }
    else
    {
      printf("Erro ao ler linha do arquivo\n");
      // Trate o erro conforme necessário
    }
  }
  fclose(arquivo);

  // Bubble Sort
  /* Só troca as linhas se ano[j] > ano[j+1] ou ,se os anos forem iguais, se o mes[j] > mes[j+1] e assim vai*/
  /* Eu fiz até o mês, e a prioridade maior do mês*/
  for (int i = 0; i < numCompromissos - 1; i++)
  {
    for (int j = 0; j < numCompromissos - i - 1; j++)
    {
      if ((compromissos[j].ano > compromissos[j + 1].ano) || (compromissos[j].ano == compromissos[j + 1].ano && compromissos[j].mes > compromissos[j + 1].mes) || (compromissos[j].mes == compromissos[j + 1].mes && compromissos[j].prioridade < compromissos[j+1].prioridade))
      {
        Compromisso temp = compromissos[j];
        compromissos[j] = compromissos[j + 1];
        compromissos[j + 1] = temp;
      }
    }
  }

  // Criando um arquivo saida.csv
  FILE *arquivoOrdenado = fopen("saida.csv", "w");

  if (arquivoOrdenado == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo\n");
    return;
  }

  // Escrevendo os compromissos no arquivo saida.csv
  for (int i = 0; i < numCompromissos; i++)
  {
    fprintf(arquivoOrdenado, "%d;%d;%d;%d;%d;%d;%d;%s;%s;%s\n",
            compromissos[i].ano,
            compromissos[i].mes,
            compromissos[i].dia,
            compromissos[i].hora,
            compromissos[i].minuto,
            compromissos[i].duracao,
            compromissos[i].prioridade,
            compromissos[i].nomeCompromisso,
            compromissos[i].descricao,
            compromissos[i].local);
  }
  fclose(arquivoOrdenado);

  // Ler o arquivo saida.csv
  arquivo = fopen("saida.csv", "r");
  if (arquivo == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo\n");
    return;
  }

  printf("\n--------------------------");
  printf(" Lista de Compromissos");
  printf("--------------------------\n");
  int contador = 0;
  char linha[100];
  while (fgets(linha, sizeof(linha), arquivo) != NULL)
  {
    printf("[%d] - %s", contador, linha);
    contador++;
  }
  fclose(arquivo);

  // Apagando arquivo saida.csv
  if (remove("saida.csv") != 0)
  {
    printf("Erro ao remover arquivo original\n");
  }
}



void ordenarLocalPrioridadeDuracao() {
  FILE *arquivo = fopen("entrada.csv", "r");

  if (arquivo == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo\n");
    return;
  }

  int numCompromissos = 0;
  Compromisso compromissos[100];
  char line[256];
  while (fgets(line, sizeof(line), arquivo) != NULL){
    if (sscanf(line, "%d;%d;%d;%d;%d;%d;%d;%99[^;];%99[^;];%99[^\n]",
              &compromissos[numCompromissos].ano,
              &compromissos[numCompromissos].mes,
              &compromissos[numCompromissos].dia,
              &compromissos[numCompromissos].hora,
              &compromissos[numCompromissos].minuto,
              &compromissos[numCompromissos].duracao,
              &compromissos[numCompromissos].prioridade,
              compromissos[numCompromissos].nomeCompromisso,
              compromissos[numCompromissos].descricao,
              compromissos[numCompromissos].local) == 10)
    {
      numCompromissos++;
    }
    else
    {
      printf("Erro ao ler linha do arquivo\n");
      // Trate o erro conforme necessário
    }
  }
  fclose(arquivo);

  // Ordenar os compromissos pelo local em ordem alfabética, prioridade e duração
  for (int i = 0; i < numCompromissos - 1; i++) {
    for (int j = i + 1; j < numCompromissos; j++) {
      int comparacaoLocal = strcmp(compromissos[i].local, compromissos[j].local);
      if (comparacaoLocal > 0 ||
                (comparacaoLocal == 0 && compromissos[i].prioridade < compromissos[j].prioridade) || (comparacaoLocal == 0 && compromissos[i].prioridade == compromissos[j].prioridade && compromissos[i].duracao < compromissos[j].duracao)) {
                Compromisso temp = compromissos[i];
                compromissos[i] = compromissos[j];
                compromissos[j] = temp;
      }
    }
  }

  // Criando um arquivo saida.csv
  FILE *arquivoOrdenado = fopen("saida.csv", "w");

  if (arquivoOrdenado == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo\n");
    return;
  }

  // Escrevendo os compromissos no arquivo saida.csv
  for (int i = 0; i < numCompromissos; i++)
  {
    fprintf(arquivoOrdenado, "%d;%d;%d;%d;%d;%d;%d;%s;%s;%s\n",
            compromissos[i].ano,
            compromissos[i].mes,
            compromissos[i].dia,
            compromissos[i].hora,
            compromissos[i].minuto,
            compromissos[i].duracao,
            compromissos[i].prioridade,
            compromissos[i].nomeCompromisso,
            compromissos[i].descricao,
            compromissos[i].local);
  }
  fclose(arquivoOrdenado);

  // Ler o arquivo saida.csv
  arquivo = fopen("saida.csv", "r");
  if (arquivo == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo\n");
    return;
  }

  printf("\n--------------------------");
  printf(" Lista de Compromissos");
  printf("--------------------------\n");
  int contador = 0;
  char linha[100];
  while (fgets(linha, sizeof(linha), arquivo) != NULL)
  {
    printf("[%d] - %s", contador, linha);
    contador++;
  }
  fclose(arquivo);

  // Apagando arquivo saida.csv
  if (remove("saida.csv") != 0)
  {
    printf("Erro ao remover arquivo original\n");
  }
}



// Função main
int main()
{
  int opc = 0;
  while (opc != 7)
  {
    printf("\n--------------------------");
    printf(" Menu ");
    printf("--------------------------\n");
    printf("[1] - Adicionar compromisso\n[2] - Remover compromisso\n[3] - Ordenar por Data\n[4] - Ordenar por Data e Horario\n[5] - Ordenar por Data e Prioridade\n[6] - Ordenar por Local, Prioridade e Duracao\n[7] - Sair do Programa");
    printf("\nDigite a sua opcao: ");

    scanf("%d", &opc);
    if (opc == 1)
    {
      int ano, mes, dia, hora, minuto, duracao, prioridade;
      char nomeCompromisso[100], descricao[100], local[100];

      printf("Digite o ano: ");
      scanf("%d", &ano);

      printf("Digite o mes: ");
      scanf("%d", &mes);
      if (mes < 1 || mes > 12) {
        printf("Erro: Mês fora do intervalo permitido (1-12)\n");
        continue;} // Volta para o início do loop

      printf("Digite o dia: ");
      scanf("%d", &dia);
      if (dia < 1 || dia > 31) {
        printf("Erro: Dia fora do intervalo permitido (1-31)\n");
        continue;}

      printf("Digite as horas: ");
      scanf("%d", &hora);
      if (hora < 0 || hora > 24){
        printf("Erro: Hora fora do intervalo permitido (1-24)\n");
        continue;}

      printf("Digite os minutos: ");
      scanf("%d", &minuto);
      if (minuto < 0 || minuto > 59){
        printf("Erro: Minuto fora do intervalo permitido (1-59)\n");
        continue;}

      printf("Digite a duracao (em horas): ");
      scanf("%d", &duracao);
      if (duracao < 0 || duracao > 24){
        printf("Erro: Duracao fora do intervalo permitido (1-24)\n");
        continue;}

      printf("Digite a prioridade (1 a 5): ");
      scanf("%d", &prioridade);
      if (prioridade < 1 || prioridade > 5){
        printf("Erro: Prioridade fora do intervalo permitido (1-5)\n");
        continue;}

      printf("Digite o nome do compromisso: ");
      getchar();
      fgets(nomeCompromisso, sizeof(nomeCompromisso), stdin); // Armazena o input na String nomeCompromisso
      nomeCompromisso[strcspn(nomeCompromisso, "\n")] = '\0'; // Remove o \n que o fgets coloca no final
      
      printf("Digite a descricao: ");
      fgets(descricao, sizeof(descricao), stdin);
      descricao[strcspn(descricao, "\n")] = '\0';
      
      printf("Digite o local: ");
      fgets(local, sizeof(local), stdin);
      local[strcspn(local, "\n")] = '\0';

      adicionarCompromisso("entrada.csv", ano, mes, dia, hora, minuto, duracao, prioridade, nomeCompromisso, descricao, local);
    }
    else if (opc == 2)
    {
      removerCompromisso();
    }
    else if (opc == 3)
    {
      ordenarData();
    }
    else if (opc == 4)
    {
      ordenarDataHorario();
    }
    else if (opc == 5)
    {
      ordenarDataPrioridade();
    }
    else if (opc == 6)
    {
      ordenarLocalPrioridadeDuracao();
    }
    else if (opc == 7)
    {
      break;
    }
    else
    {
      printf("Digite uma opcao válida!");
    }
  }
}
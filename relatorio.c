#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "relatorio.h"
#include "cliente.h"
#include "funcionario.h"
#include "queijo.h"
#include "validacao.h"

void menu_relatorio(void) {      // Menu inicial, ainda será reestruturado para as outras semanas
    char op[2];
    do {
        system("clear||cls");
        printf("\n");  
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("|                       * * * Módulo Relatório * * *                        |\n");
        printf("|                                                                           |\n");
        printf("|-> 1. Lista dos clientes cadastrados                                       |\n");
        printf("|-> 2. Lista dos funcionários cadastrados                                   |\n");
        printf("|-> 3. Lista dos queijos cadastrados                                        |\n");
        printf("|-> 4. Lista de clientes por bairro                                         |\n");
        printf("|-> 0. Voltar ao menu anterior                                              |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("\n");
        printf("               Escolha a opção desejada: ");
        fgets(op, sizeof(op), stdin);
        op[strcspn(op, "\n")] = '\0';    // Remover a quebra de linha
        getchar();
    
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        switch(op[0]) {
          case '1':
            relatorio_cliente();
            break;
          case '2':
            relatorio_funcionario();
            break;
          case '3':
            relatorio_queijo();
            break;
           case '4':
            lista_clientes_por_bairro();
            break;
          case '0':
            printf("Voltando ao menu anterior...\n");
            break;
          default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }
    } while (op[0] != '0');
}

void relatorio_cliente(void) {
  FILE* fp;
  
  char arquivo[] = "clientes.dat";
  Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));     // Variável para armazenar cada registro
  if (cliente == NULL) {
      perror("Erro ao alocar memória em cliente");
      exit(1);
  }
  
  system("clear||cls");
  printf("\n");
  printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
  printf("|                                                                                                                                 |\n");
  printf("|                                         >>  Relatório dos Clientes  <<                                                          |\n");
  printf("|                                                                                                                                 |\n");
  printf("| %-30s %-15s %-30s %-12s %-15s %-20s %-20s %-20s %-15s \n", 
           "Nome", "CPF", "E-mail", "Nascimento", "Telefone", "Bairro", "Cidade", "Estado", "Situação");
  printf("|                                                                                                                                 |\n");
  fp = fopen(arquivo, "rb");
    
  if (fp == NULL) {
    perror("Erro ao abrir o arquivo!\n");
    exit(1);
  }

  // Leitura e exibição dos dados
  int count = 0;  // Contador de clientes lidos
  while (fread(cliente, sizeof(Cliente), 1, fp) == 1) {
      // Exibe o status do cliente: "Ativo" ou "Inativo"
      const char* status_cliente = (cliente->status == 'a') ? "Ativo" : "Inativo";
    
      printf("| %-30s %-15s %-30s %-12s %-15s %-20s %-20s %-20s %-15s \n", 
               cliente->nome, cliente->cpf, cliente->email, cliente->data, cliente->fone, 
               cliente->endereco.bairro, cliente->endereco.cidade, cliente->endereco.estado, status_cliente);
      count++;
  }

  if (count == 0) {
    printf("Nenhum cliente encontrado.\n");
  }
  
  printf("|                                                                                                                                 |\n");
  printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
  printf("\t\t\t>>> Tecle ENTER para continuar...\n");
  getchar(); 
  
  fclose (fp);                  // Fecha o arquivo
  free (cliente);               // libera memória da estrutura Cliente
}


void relatorio_funcionario(void) {
  system("clear||cls");
  printf("\n");
  printf("+---------------------------------------------------------------------------+\n");
  printf("|                                                                           |\n");
  printf("|                         >>  Relatório dos Funcionários  <<                |\n");
  printf("|                                                                           |\n");
  printf("+---------------------------------------------------------------------------+\n");
  printf("\t\t\t>>> Tecle ENTER para continuar...\n");
  getchar(); 
}
    
void relatorio_queijo(void) {
  system("clear||cls");
  printf("\n");
  printf("+---------------------------------------------------------------------------+\n");
  printf("|                                                                           |\n");
  printf("|                         >>  Relatório dos Queijos <<                      |\n");
  printf("|                                                                           |\n");
  printf("+---------------------------------------------------------------------------+\n");
  printf("\t\t\t>>> Tecle ENTER para continuar...\n");
  getchar(); 
}

void lista_clientes_por_bairro(void) {
  char bairro_lido[30];  // Definindo a variável bairro_lido
  system("clear||cls");
  printf("\n");
  printf("+---------------------------------------------------------------------------+\n");
  printf("|                                                                           |\n");
  printf("|                   >>  Relatório dos clientes por bairro  <<               |\n");
  leBairroRelatorio(bairro_lido);
  buscaBairroRelatorio(bairro_lido);
}

void buscaBairroRelatorio(char* bairro_lido) {
  FILE *fp;
  Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));
  int encontrou = 0;  // Variável para verificar se algum cliente foi encontrado

  fp = fopen("clientes.dat", "rb");
  if (fp == NULL) {
      perror("Erro ao abrir o arquivo clientes.dat");
      exit(1);
  }

  while(fread(cliente, sizeof(Cliente), 1, fp)) {
      if (strcmp(cliente->endereco.bairro, bairro_lido) == 0 && cliente->status == 'a') {
          exibe_cliente(cliente);
          encontrou = 1;          // Marca que encontrou ao menos um cliente
      }
  }
  
  fclose(fp);
  free (cliente);

  if (!encontrou) {
        printf("\nNenhum cliente ativo encontrado no bairro \"%s\".\n", bairro_lido);
  }
  printf("\n>>> Tecle <ENTER> para continuar...\n");
  getchar();
}


void leBairroRelatorio(char* bairro_lido) {
  printf("Digite o bairro para o relatório: ");
  do {
      fgets(bairro_lido, 30, stdin);
      bairro_lido[strcspn(bairro_lido, "\n")] = '\0';  // Remove o '\n'
    
      if (validaNome(bairro_lido)) {
            break;
        } else {
            printf("Bairro inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("Digite o bairro para o relatório: ");
        }
    } while (!validaNome(bairro_lido));
}

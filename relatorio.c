#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "relatorio.h"
#include "cliente.h"
#include "funcionario.h"
#include "queijo.h"

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
  printf("| %-30s %-15s %-30s %-12s %-15s \n",  "Nome", "CPF", "E-mail", "Nascimento", "Telefone");
  printf("|                                                                                                                                 |\n");
  fp = fopen(arquivo, "rb");
    
  if (fp == NULL) {
    perror("Erro ao abrir o arquivo!\n");
    exit(1);
  }

  // Leitura e exibição dos dados
  int count = 0;  // Contador de clientes lidos
  while (fread(cliente, sizeof(Cliente), 1, fp) == 1) {
      printf("| %-30s %-15s %-30s %-12s %-15s \n", 
        cliente->nome, cliente->cpf, cliente->email, cliente->data, cliente->fone);
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "relatorio.h"
#include "funcionario.h"
#include "queijo.h"
#include "validacao.h"
#include "venda.h"

// Separar os relatórios em módulos
// Organizar os relatórios gerais

extern Cliente* lista;  // Declaração externa da variável global 'lista'

void menu_relatorio(void) {
    char op[2];
    do {
        system("clear||cls");
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("|                       * * * Módulo Relatório * * *                        |\n");
        printf("|                                                                           |\n");
        printf("|-> 1. Relatório dos clientes cadastrados                                   |\n");
        printf("|-> 2. Relatório dos funcionários cadastrados                               |\n");
        printf("|-> 3. Relatório dos queijos cadastrados                                    |\n");
        printf("|-> 4. Relatório de clientes por bairro                                     |\n");
        printf("|-> 5. Relatório de queijos por tipo                                        |\n");
        printf("|-> 6. Relatório das vendas por cpf                                         |\n");
        printf("|-> 7. Lista dos clientes                                                   |\n");
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
           case '5':
                lista_queijo_tipo();
                break;
           case '6':
                busca_cliente_por_compras();
                break;
           case '7':
                menu_listas_cliente(lista);
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
   FILE* fp;

  char arquivo[] = "funcionarios.dat";
  Funcionario *funcionario = (Funcionario*) malloc(sizeof(Funcionario));     // Variável para armazenar cada registro
  if (funcionario == NULL) {
      perror("Erro ao alocar memória em funcionario");
      exit(1);
  }
  system("clear||cls");
  printf("\n");
  printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
  printf("|                                                                                                                                 |\n");
  printf("|                                         >>  Relatório dos Funcionários  <<                                                      |\n");
  printf("|                                                                                                                                 |\n");
  printf("| %-30s %-15s %-30s %-12s %-15s %-20s \n",
           "Nome", "CPF", "E-mail", "Nascimento", "Telefone","Situação");
  printf("|                                                                                                                                 |\n");
  fp = fopen(arquivo, "rb");

  if (fp == NULL) {
    perror("Erro ao abrir o arquivo!\n");
    exit(1);
  }

  // Leitura e exibição dos dados
  int count = 0;  // Contador de funcionarios lidos
  while (fread(funcionario, sizeof(Funcionario), 1, fp) == 1) {
      // Exibe o status do funcionario: "Ativo" ou "Inativo"
      const char* status_funcionario = (funcionario->status == 'a') ? "Ativo" : "Inativo";

      printf("|%-30s %-15s %-30s %-12s %-15s %-20s \n",
               funcionario->nome, funcionario->cpf, funcionario->email, funcionario->data, funcionario->fone,status_funcionario);
      count++;
  }

  if (count == 0) {
    printf("Nenhum funcionario encontrado.\n");
  }

  printf("|                                                                                                                                 |\n");
  printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
  printf("\t\t\t>>> Tecle ENTER para continuar...\n");
  getchar();

  fclose (fp);                  // Fecha o arquivo
  free (funcionario);               // libera memória da estrutura funcionario
}

void relatorio_queijo(void) {
  FILE* fp;

  char arquivo[] = "queijos.dat";
  Queijo *queijo = (Queijo*) malloc(sizeof(Queijo));      // Aloca dinamicamente memória para a estrutura
    if (queijo == NULL) {
        perror("Erro ao alocar memória em queijo");
        exit(1);
    }

  system("clear||cls");
  printf("\n");
  printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
  printf("|                                                                                                                                 |\n");
  printf("|                                         >>  Relatório dos Queijos  <<                                                           |\n");
  printf("|                                                                                                                                 |\n");
  printf("| %-30s %-15s %-30s %-12s %-15s %-20s %-20s  \n",
           "Nome", "Codigo", "Fabricação", "Vencimento", "Composição","Tipo","Situação");
  printf("|                                                                                                                                 |\n");
  fp = fopen(arquivo, "rb");

  if (fp == NULL) {
    perror("Erro ao abrir o arquivo!\n");
    exit(1);
  }

  // Leitura e exibição dos dados
  int count = 0;  // Contador de clientes lidos
  while (fread(queijo, sizeof(Queijo), 1, fp) == 1) {
      // Exibe o status do queijo: "Ativo" ou "Inativo"
      const char* status_queijo = (queijo->status == 'a') ? "Ativo" : "Inativo";

      printf("|%-30s %-15s %-30s %-12s %-15s %-20s %-20s \n",
               queijo->nome, queijo->codigo, queijo->data_fabricacao, queijo->data_validade, queijo->comp,queijo->tipo,status_queijo);
      count++;
  }

  if (count == 0) {
    printf("Nenhum queijo encontrado.\n");
  }

  printf("|                                                                                                                                 |\n");
  printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
  printf("\t\t\t>>> Tecle ENTER para continuar...\n");
  getchar();

  fclose (fp);                  // Fecha o arquivo
  free (queijo);               // libera memória da estrutura queijo
}

void lista_queijo_tipo(void){
  char tipo_lido[30];
  system("clear||cls");
  printf("\n");
  printf("+---------------------------------------------------------------------------+\n");
  printf("|                                                                           |\n");
  printf("|                   >>  Relatório dos queijos por tipo  <<                  |\n");
  leTipoRelatorio(tipo_lido);
  busca_tipo_queijo_Relatorio(tipo_lido);
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

void busca_cliente_por_compras(void) {
    char cpf_relatorio[13];
    int continuar = 1;

    while (continuar) {
        system("clear||cls");
        printf("\n");
        printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                                                                                                 |\n");
        printf("|                                     >>  Relatório do cliente por compras  <<                                                    |\n");
        printf("|                                                                                                                                 |\n");

        leCpfRelatorio(cpf_relatorio);
        buscaVendas(cpf_relatorio);

        // Pergunta se o usuário deseja continuar
        printf("\nDeseja realizar outra busca? (1 - Sim / 0 - Não): ");
        scanf("%d", &continuar);
        while (getchar() != '\n'); // Limpa o buffer
    }
}

void menu_listas_cliente(Cliente* lista) {
    char ordem;

    printf("Voce deseja exibir a lista dos clientes em qual ordem?\n");
    printf("1 - Ordem direta\n");
    printf("2 - Ordem clientes ativos(Filtro)\n");
    printf("3 - Ordem alfabética clientes\n");
    scanf("%c", &ordem);
    getchar();
    
   if (ordem == '1') {
        lista_direta_cliente(lista);  // Exibe todos os clientes em ordem direta
    } else if (ordem == '2') {
        lista_cliente_ativos(lista);  // Exibe apenas clientes ativos (com filtro)
    } else if (ordem == '3') {
        lista_alfa_cliente(lista);  // Exibe apenas clientes ativos (com filtro)
    } else {
        printf("Opção inválida. Tente novamente.\n");
    }
}

void lista_direta_cliente(Cliente* lista) {
    FILE* fp = fopen("clientes.dat", "rb");  // Abre o arquivo para leitura binária
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de clientes");
        return;
    }

    // Lista dinâmica para armazenar todos os clientes
    Cliente* lista_clientes = NULL;

    // Variável temporária para armazenar os dados lidos do arquivo
    Cliente novo_cliente;
    while (fread(&novo_cliente, sizeof(Cliente), 1, fp)) {
        // Aloca memória para um novo nó de cliente
        Cliente* novo_node = (Cliente*)malloc(sizeof(Cliente));
        if (novo_node == NULL) {
            printf("Erro de alocação de memória\n");
            fclose(fp);
            return;
        }

        // Copia os dados do cliente lido para o novo nó
        *novo_node = novo_cliente;
        // Insere o novo nó no início da lista ligada
        novo_node->prox = lista_clientes;
        lista_clientes = novo_node;  
    }

    fclose(fp);

    // Verifica se a lista de clientes está vazia
    if (lista_clientes == NULL) {
        printf("\nNenhum cliente cadastrado.\n");
        printf("\nTecle ENTER para continuar...\n");
        getchar();
        return;
    }

    printf("\nLista de Todos os Clientes Cadastrados:\n");
    printf("=====================================\n");

    // Exibe os dados de cada cliente na lista
    int i = 1;
    Cliente* atual = lista_clientes;

    while (atual != NULL) {
        printf("\nCliente %d:\n", i);
        printf("Nome: %s\n", atual->nome);
        printf("CPF: %s\n", atual->cpf);
        printf("Fone: %s\n", atual->fone);
        printf("=====================================\n");
        printf("\n");
        atual = atual->prox;  // Avança para o próximo cliente
        i++;  // Incrementa o contador de clientes
    }

    printf("\nTecle ENTER para continuar...\n");
    getchar();
}

void lista_cliente_ativos(Cliente* lista) {     // Créditos ao GPT   (22/01/2025)
    FILE* fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de clientes");
        return;
    }

    // lista_filtrada: Lista dinâmica que irá armazenar os clientes que atendem ao critério de filtro (status ativo).
    // novo_cliente: Variável temporária usada para armazenar os dados de um cliente lido do arquivo.
    // novo_node: Ponteiro para um novo nó de cliente alocado dinamicamente. Cada nó contém os dados de um cliente e é adicionado à lista filtrada.

    
    // Lista dinâmica que será criada com os dados do arquivo
    Cliente* lista_filtrada = NULL;

    // Variável temporária para armazenar os dados lidos do arquivo
    Cliente novo_cliente;
    while (fread(&novo_cliente, sizeof(Cliente), 1, fp)) {
        if (novo_cliente.status == 'a') {  
            
             // Aloca memória para um novo nó de cliente
            Cliente* novo_node = (Cliente*)malloc(sizeof(Cliente));
            if (novo_node == NULL) {
                printf("Erro de alocação de memória\n");
                fclose(fp);
                return;
            }

            // Copia os dados de novo_cliente para o novo_node
            *novo_node = novo_cliente;
            
            // Insere o novo nó no início da lista ligada
            novo_node->prox = lista_filtrada;
            lista_filtrada = novo_node;  // Insere no início da lista
        }
    }

    fclose(fp);

    if (lista_filtrada == NULL) {
        printf("\nNenhum cliente cadastrado com o critério especificado.\n");
        printf("\nTecle ENTER para continuar...\n");
        getchar();
        return;
    }

    printf("\nLista dos Clientes Cadastrados (Ativos):\n");
    printf("=====================================\n");

    // Anda pela lista e exibe as informações de cada cliente
    int i = 1;
    Cliente* atual = lista_filtrada;

    while (atual != NULL) {
        printf("\nCliente %d:\n", i);
        printf("Nome: %s\n", atual->nome);
        printf("CPF: %s\n", atual->cpf);
        printf("Fone: %s\n", atual->fone);
        printf("=====================================\n");
        printf("\n");
        atual = atual->prox;  // Avança para o próximo cliente
        i++;  // Incrementa o contador de clientes
    }

    printf("\nTecle ENTER para continuar...\n");
    getchar();
}

void lista_alfa_cliente(Cliente* lista) {         // Créditos ao GPT e ClaudeAI (23/01/2025)
    FILE* fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de clientes");
        return;
    }

    // Lista dinâmica para armazenar clientes ordenados
    Cliente* lista_clientes = NULL;
    Cliente novo_cliente;

    // Leitura dos clientes do arquivo com inserção ordenada
    while (fread(&novo_cliente, sizeof(Cliente), 1, fp)) {
        // Aloca memória para um novo nó de cliente
        Cliente* novo_node = (Cliente*)malloc(sizeof(Cliente));
        if (novo_node == NULL) {
            printf("Erro de alocação de memória\n");
            fclose(fp);
            return;
        }
        *novo_node = novo_cliente;
        novo_node->prox = NULL;

        // Inserção ordenada por nome
        if (lista_clientes == NULL) {
            lista_clientes = novo_node;
        } else if (strcmp(novo_node->nome, lista_clientes->nome) < 0) {
            // Inserir no início se alfabeticamente menor
            novo_node->prox = lista_clientes;
            lista_clientes = novo_node;
        } else {
            // Encontrar posição de inserção
            Cliente* ant = lista_clientes;
            Cliente* atual = lista_clientes->prox;

            while (atual != NULL && strcmp(novo_node->nome, atual->nome) > 0) {
                ant = atual;
                atual = atual->prox;
            }

            novo_node->prox = atual;
            ant->prox = novo_node;
        }
    }
    fclose(fp);

    // Verifica se a lista de clientes está vazia
    if (lista_clientes == NULL) {
        printf("\nNenhum cliente cadastrado.\n");
        printf("\nTecle ENTER para continuar...\n");
        getchar();
        return;
    }

    printf("\nLista de Clientes Cadastrados (Ordem Alfabética):\n");
    printf("=====================================\n");
    
    // Exibe os dados de cada cliente na lista
    int i = 1;
    Cliente* atual = lista_clientes;
    while (atual != NULL) {
        printf("\nCliente %d:\n", i);
        printf("Nome: %s\n", atual->nome);
        printf("CPF: %s\n", atual->cpf);
        printf("Fone: %s\n", atual->fone);
        printf("=====================================\n");
        printf("\n");
        atual = atual->prox;
        i++;
    }

    printf("\nTecle ENTER para continuar...\n");
    getchar();

    // Liberar memória alocada
    atual = lista_clientes;
    while (atual != NULL) {
        Cliente* temp = atual;
        atual = atual->prox;
        free(temp);
    }
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

void busca_tipo_queijo_Relatorio(char* tipo_lido) {
  FILE *fp;
  Queijo *queijo = (Queijo*) malloc(sizeof(Queijo));
  int encontrou = 0;  // Variável para verificar se algum queijo foi encontrado

  fp = fopen("queijos.dat", "rb");
  if (fp == NULL) {
      perror("Erro ao abrir o arquivo queijos.dat");
      exit(1);
  }

  while(fread(queijo, sizeof(Queijo), 1, fp)) {
      if (strcmp(queijo->tipo, tipo_lido) == 0 && queijo->status == 'a') {
          exibe_queijo(queijo);
          encontrou = 1;          // Marca que encontrou ao menos um queijo
      }
  }

  fclose(fp);
  free (queijo);

  if (!encontrou) {
        printf("\nNenhum queijo do tipo \"%s\".\n", tipo_lido);
  }
  printf("\n>>> Tecle <ENTER> para continuar...\n");
  getchar();
}

void leTipoRelatorio(char* tipo_lido) {
  printf("Digite o tipo de queijo para o relatório(cru ou pasteurizado): ");
  do {
      fgets(tipo_lido, 30, stdin);
      tipo_lido[strcspn(tipo_lido, "\n")] = '\0';  // Remove o '\n'

      if (validaNome(tipo_lido)) {
            break;
        } else {
            printf("Tipo inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("Digite o tipo de queijo para o relatório(cru ou pasteurizado): ");
        }
    } while (!validaNome(tipo_lido));
}

void buscaVendas(const char *cpf_relatorio) {
    FILE *fp_clientes, *fp_vendas, *fp_queijos;

    Cliente cliente;
    Queijo queijo;
    Venda venda;

    fp_vendas = fopen("vendas.dat", "rb");
    if (fp_vendas == NULL) {
        perror("Erro ao abrir o arquivo de vendas!");
        getchar();
        return;
    }

    fp_clientes = fopen("clientes.dat", "rb");
    if (fp_clientes == NULL) {
        perror("Erro ao abrir o arquivo de clientes!");
        getchar();
        fclose(fp_clientes);
        return;
    }

    fp_queijos = fopen("queijos.dat", "rb");
    if (fp_queijos == NULL) {
        perror("Erro ao abrir o arquivo de queijos!");
        getchar();
        fclose(fp_queijos);
        return;
    }

    int vendas_encontrada = 0;
    while (fread(&venda, sizeof(Venda), 1, fp_vendas)) {
        if (strcmp(venda.cpf_cliente, cpf_relatorio) == 0) {
            vendas_encontrada = 1;

            // Busca o nome do cliente através do CPF
            rewind(fp_clientes);                           // reposiciona o ponteiro de leitura/escrita no início do arquivo
            int cliente_encontrado = 0;
            while (fread(&cliente, sizeof(Cliente), 1, fp_clientes)) {
                if (strcmp(cliente.cpf, cpf_relatorio) == 0) {
                    printf("\n+---------------------------------------------------------------------------+\n");
                    printf("| Nome do comprador: %s\n", cliente.nome);
                    cliente_encontrado = 1;
                    break;
                }
            }
            if (!cliente_encontrado) {
                printf("| O cliente com este CPF %s não foi encontrado no sistema.\n", cpf_relatorio);
                getchar();
            }

            // Busca o nome do queijo no arquivo queijos.dat
            rewind(fp_queijos);                                               // reposiciona o ponteiro de leitura/escrita no início do arquivo
            while (fread(&queijo, sizeof(Queijo), 1, fp_queijos)) {
                if (strcmp(queijo.codigo, venda.codigo_produto) == 0) {
                    printf("| Nome do produto: %s\n", queijo.nome);
                    break;
                }
            }

            printf("| Código do produto: %s\n", venda.codigo_produto);
            printf("| Quantidade: %.2f\n", venda.quantidade_comprada);
            printf("| Data: %s\n", venda.data);
            printf("+---------------------------------------------------------------------------+\n");
        }
    }
    if (!vendas_encontrada) {
        printf("\n| Nenhuma venda encontrada para o CPF informado.\n");
        getchar();
    }

    fclose(fp_vendas);
    fclose(fp_clientes);
}

void leCpfRelatorio(char *cpf) {
    printf("|-> CPF (somente números): ");
    do {
        scanf("%12s", cpf);
        if (validaCPF(cpf)) {
            printf("CPF válido\n");
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER\n");
            getchar();
            printf("|-> CPF (somente números): ");
        }
    } while (!validaCPF(cpf));
}

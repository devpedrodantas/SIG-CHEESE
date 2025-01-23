#include <stdio.h> 
#include <stdlib.h>
#include <string.h>   
#include <time.h>
#include "entradas.h"
#include "validacao.h"
#include "estruturas.h"
#include "venda.h"


void menu_venda(void) {
    char op;
    do {
        system("clear||cls");
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("|                         * * * Módulo Venda * * *                          |\n");
        printf("|                                                                           |\n");
        printf("|-> 1. Realizar venda                                                       |\n");
        printf("|-> 2. Exibir venda                                                         |\n");
        printf("|-> 3. Atualizar venda                                                      |\n");
        printf("|-> 4. Cancelar venda                                                       |\n");
        printf("|-> 5. Estoque                                                              |\n");
        printf("|-> 0. Voltar ao menu anterior                                              |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("\n");
        printf("               Escolha a opção desejada: ");
        scanf("%c", &op);
        getchar();
        printf("\n");                                                                        
        printf("+---------------------------------------------------------------------------+\n");
        switch (op) {
            case '1':
                cadastra_venda();
                break;
            case '2':
                pesquisa_venda();
                break;
            case '3':
                atualiza_venda();
                break;
            case '4':
                exclui_venda();
                break;
            case '5':
                atualiza_estoque();
                break;
            case '0':
                printf("Voltando ao menu principal\n");
                printf("\n");
                printf("\t\t\t>>> Tecle ENTER para continuar...\n");
                getchar();
                break;
            default:
                printf("Opção inválida, digite um dígito entre os disponíveis\n");
                printf("\n");
                printf("\t\t\t>>> Tecle ENTER para continuar...\n");
                getchar(); 
                break;	
        }
    } while (op != '0');
}

void cadastra_venda(void) {
    char cpf_busca[13];
    char codigo_busca[10];
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                            >>  Cadastrar Venda  <<                        |\n");
    printf("|                                                                           |\n");

    // Realizando a compra
    realiza_compra(cpf_busca, codigo_busca);  // Reutilizando a função de realizar a compra

    printf("+---------------------------------------------------------------------------+\n");
    printf("\t\t\t>>> Tecle ENTER para continuar...\n");
    getchar(); 
}

void realiza_compra() {     // Créditos ao GPT (19/01/2025)
    char cpf_cliente[13];
    char codigo_busca[10];
    float quantidade;
    FILE *fp_produtos, *fp_clientes;
    Queijo queijo;
    int cliente_encontrado = 0;

    // Solicitar o CPF do cliente
    leCpfBusca(cpf_cliente);

    // Validar se o cliente está cadastrado
    fp_clientes = fopen("clientes.dat", "rb");
    if (fp_clientes == NULL) {
        perror("Erro ao abrir o arquivo de clientes!");
        exit(1);
    }

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, fp_clientes)) {
        if (strcmp(cliente.cpf, cpf_cliente) == 0) {
            cliente_encontrado = 1;
            break;
        }
    }
    fclose(fp_clientes);
    
    // Verificar se o cliente foi encontrado e exibir as informações
    if (cliente_encontrado) {
        printf("\nInformações do Cliente:\n");
        exibe_cliente(&cliente);
    } else {
        printf("Cliente não encontrado. É necessário realizar o cadastro primeiro.\n");
        return;
    }
    
    // Abrir o arquivo de produtos
    fp_produtos = fopen("queijos.dat", "rb+");
    if (fp_produtos == NULL) {
        perror("Erro ao abrir o arquivo de produtos!");
        exit(1);
    }

    // Solicitar o código do produto
    leCodigoBusca(codigo_busca);

    int produto_encontrado = 0;

    // Buscar o produto no arquivo
    while (fread(&queijo, sizeof(Queijo), 1, fp_produtos)) {
        if (strcmp(queijo.codigo, codigo_busca) == 0) {
            produto_encontrado = 1;

            // Exibir detalhes do produto
            printf("\n+---------------------------------------------------------------------------+\n");
            printf("| Produto encontrado:\n");
            printf("| Nome: %s\n", queijo.nome);
            printf("| Código: %s\n", queijo.codigo);
            printf("| Composição/Ingredientes: %s\n", queijo.comp);
            printf("| Estoque disponível: %d\n", queijo.estoque);
            printf("| Preço unitário: %.2f\n", queijo.preco);
            printf("+---------------------------------------------------------------------------+\n");

            // Solicitar a quantidade desejada
            printf("\nInforme a quantidade desejada: ");
            scanf("%f", &quantidade);
            getchar(); // Limpar buffer

            // Verificar se há estoque suficiente
            if (quantidade > queijo.estoque) {
                printf("Quantidade indisponível no estoque.\n");
                fclose(fp_produtos);
                return;
            }

            // Atualizar estoque do produto
            queijo.estoque -= quantidade;
            fseek(fp_produtos, -sizeof(Queijo), SEEK_CUR);
            fwrite(&queijo, sizeof(Queijo), 1, fp_produtos);

            // Registrar a venda
            registra_venda(cpf_cliente, &queijo, quantidade);

            printf("Compra realizada com sucesso!\n");
            printf("Estoque atualizado: %d\n", queijo.estoque);
            break;
        }
    }

    if (!produto_encontrado) {
        printf("Produto não encontrado.\n");
    }

    fclose(fp_produtos);
}


void registra_venda(const char *cpf_cliente, Queijo *queijo, float quantidade) {
    FILE *fp;
    Venda venda;
    time_t t;
    struct tm *tm_info;

    // Preencher os dados da venda
    strcpy(venda.cpf_cliente, cpf_cliente);
    strcpy(venda.codigo_produto, queijo->codigo);
    venda.quantidade_comprada = quantidade;
    venda.preco_total = quantidade * queijo->preco;

    // Obter data atual do sistema
    t = time(NULL);
    tm_info = localtime(&t);
    strftime(venda.data, sizeof(venda.data), "%d/%m/%Y", tm_info); // Formato: DD/MM/YYYY

    // Abrir arquivo de vendas
    fp = fopen("vendas.dat", "ab");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de vendas!");
        exit(1);
    }

    fwrite(&venda, sizeof(Venda), 1, fp);
    fclose(fp);

    // Exibir detalhes da venda registrada
    printf("\nVenda registrada com sucesso!\n");
    printf("CPF do cliente: %s\n", venda.cpf_cliente);
    printf("Código do produto: %s\n", venda.codigo_produto);
    printf("Quantidade: ");
    if (venda.quantidade_comprada == (int)venda.quantidade_comprada) {
        // Exibe sem casas decimais se for um número inteiro
        printf("%.0f\n", venda.quantidade_comprada);
    } else {
        // Exibe com duas casas decimais se for um número decimal
        printf("%.2f\n", venda.quantidade_comprada);
    }

    printf("Total: %.2f\n", venda.preco_total);
    printf("Data: %s\n", venda.data);
}

void pesquisa_venda(void) {
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                            >>  Pesquisa Venda  <<                         |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\t\t\t>>> Tecle ENTER para continuar...\n");
    getchar(); 
}

void atualiza_venda(void) {
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                            >>  Atualiza Venda  <<                         |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\t\t\t>>> Tecle ENTER para continuar...\n");
    getchar(); 
}

void exclui_venda(void) {
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                             >>  Exclui Venda <<                         |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\t\t\t>>> Tecle ENTER para continuar...\n");
    getchar(); 
}

void atualiza_estoque(void) {
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                           >>  Atualiza Estoque  <<                        |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\t\t\t>>> Tecle ENTER para continuar...\n");
    getchar(); 
}

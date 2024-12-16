#include <stdio.h> 
#include <stdlib.h>
#include <string.h>           // Para usar o strcpy
#include "cliente.h"
#include "entradas.h"
#include "validacao.h"

void menu_cliente(void) {
    char op;
    do {
        system("clear||cls");
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("|                        * * * Módulo Cliente * * *                         |\n");
        printf("|                                                                           |\n");
        printf("|-> 1. Cadastrar um novo cliente                                            |\n");
        printf("|-> 2. Pesquisar os dados de um cliente                                     |\n");
        printf("|-> 3. Atualizar os dados de um cliente                                     |\n");
        printf("|-> 4. Excluir um cliente do sistema                                        |\n");
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
                cadastra_cliente();
                break;
            case '2':
                pesquisa_cliente();
                break;
            case '3':
                atualiza_cliente();
                break;
            case '4':
                exclui_cliente();
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

void cadastra_cliente(void) {
    char situacao[20];
    
    Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));      // Aloca dinamicamente memória para a estrutura Cliente
    if (cliente == NULL) {
        perror("Erro ao alocar memória em cliente");
        exit(1);
    }

    FILE* fp;  // Ponteiro para o arquivo
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Cadastrar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    /// Ainda será implementado >>> printf("|-> Endereço: ");;
    /// + opções de entradas de dados

    leNomeCliente(cliente);                 // Chama a função que agora lê e valida o nome do cliente
    
    // Necessário verificar se o CPF inserido já não está cadastrado
    leCpfCliente(cliente);                  // Chama a função que agora lê e valida o CPF do cliente
    leEmailCliente(cliente);                // Chama a função que agora lê e valida o Email do cliente
    leDataCliente(cliente);                 // Chama a função que agora lê e valida a data do cliente
    leFoneCliente(cliente);                 // Chama a função que agora lê e valida o telefone do cliente
    
    cliente->status = 'a';                  // Atualiza o status do cliente para 'ativo'
    strcpy(situacao, "Ativo");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");

    // Exibe as informações para o usuário
    if (cliente->status == 'x') {
        printf("Cliente Inexistente");
    } else {
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| Cliente cadastrado com sucesso\n");
        printf("|\n");
        printf("| Nome: %s\n", cliente->nome);
        printf("| CPF: %s\n", cliente->cpf);
        printf("| Email: %s\n", cliente->email);
        printf("| Data de nascimento: %s\n", cliente->data);
        printf("| Número de telefone: %s\n", cliente->fone);
        printf("| Situação do cliente: %s\n", situacao);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }

    fp = fopen ("clientes.dat", "ab");
    if(fp == NULL) {
        perror("Erro ao abrir o arquivo clientes.dat");
        exit(1);  // Mantém a saída do programa caso haja um erro ao abrir o arquivo
    }
    fwrite(cliente, sizeof(Cliente), 1, fp);

    fclose (fp);  //Fecha o arquivo
    free (cliente);                        //libera memória da estrutura Cliente

    
    // A pedido de Flavius (Informações em arquivo texto chamada a partir de clientes.txt) 
    //fprintf(fp, "+---------------------------------------------------------------------------+\n");
    //fprintf(fp, "| Nome: %s\n", cliente->nome);
    //fprintf(fp, "| CPF: %s\n", cliente->cpf);
    //fprintf(fp, "| Email: %s\n", cliente->email);
    //fprintf(fp, "| Data de nascimento: %s\n", cliente->data);
    //fprintf(fp, "| Número de telefone: %s\n", cliente->fone);                                                              
    //fprintf(fp, "+---------------------------------------------------------------------------+\n");
}

// Função para validar o CPF informado pelo usuário e acionar a busca do cliente
void pesquisa_cliente(void) {
    char cpf_busca[13];
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Pesquisar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    
    printf("|-> CPF para pesquisa (somente números): ");     // Criar uma nova função parecida com o leCpfCliente mas para cpf_busca
    do {
        fgets(cpf_busca, 13, stdin);
        cpf_busca[strcspn(cpf_busca, "\n")] = '\0';  // Remove o '\n' do final

        if (validaCPF(cpf_busca)) {
            printf("CPF válido\n");
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER\n");
            getchar();  // Aguarda a tecla ENTER para evitar erro de input
        }
    } while (!validaCPF(cpf_busca));  // Continua até o CPF ser válido
    
    busca_cliente(cpf_busca);     // Busca o cliente pelo CPF informado e exibe-o 
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

// Função responsável por buscar e exibir os dados de um cliente com base no CPF informado
void busca_cliente (const char *cpf_busca) {
    FILE *fp;
    Cliente *cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
  
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    int encontrado = 0;
        // Ler os dados do arquivo cliente por cliente
    while (fread(cliente, sizeof(Cliente), 1, fp)) {
  

        // Verifica se o CPF corresponde ao que foi procurado
        if (strcmp(cliente->cpf, cpf_busca) == 0) {
            printf("+---------------------------------------------------------------------------+\n");
            printf("| Cliente encontrado\n");
            printf("| Nome: %s\n", cliente->nome);
            printf("| CPF: %s\n", cliente->cpf);
            printf("| Email: %s\n", cliente->email);
            printf("| Data de nascimento: %s\n", cliente->data);
            printf("| Telefone: %s\n", cliente->fone);
            printf("+---------------------------------------------------------------------------+\n");
            encontrado = 1;
            break; // Encerra o loop quando encontrar o cliente
        }
    }
    if (!encontrado) {
        printf("Cliente não encontrado\n");
    }
    fclose(fp);  // Fecha o arquivo após o uso
}

void atualiza_cliente(void) {
    Cliente cliente; // Declara uma variável do tipo Cliente
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Atualizar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe seu CPF: ");
    do {
        leCpfCliente(&cliente);
        if (validaCPF(cliente.cpf)) {
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Informe seu CPF: ");
        }
    } while(!validaCPF(cliente.cpf));
    
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("CPF inserido: %s\n", cliente.cpf);  // Acessa o campo cpf do struct

    //    Dados do cliente atualizados:
    //    printf("Nome: %s\n", nome);
    //    printf("CPF: %s\n", cpf);
    //    printf("Email: %s\n", email);
    //    printf("Data de nascimento: %s\n", data);
    //    printf("Número de telefone: %s\n", fone); 

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void exclui_cliente(void) {
    Cliente cliente; // Declara uma variável do tipo Cliente
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                          >>  Excluir Cliente  <<                          |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe seu CPF: ");
    do {
        leCpfCliente(&cliente);
        if (validaCPF(cliente.cpf)) {
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Informe seu CPF: ");
        }
    } while(!validaCPF(cliente.cpf));
    
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("CPF inserido: %s\n", cliente.cpf);  // Acessa o campo cpf do struct

    //    Cliente excluído:
    //    printf("Nome: %s\n", nome);
    //    printf("CPF: %s\n", cpf);
    //    printf("Email: %s\n", email);
    //    printf("Data de nascimento: %s\n", data);
    //    printf("Número de telefone: %s\n", fone); 

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
